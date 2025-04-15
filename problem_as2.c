#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "problem_mk.h"

struct instr_t decode_command(unsigned char cmd) {
    struct instr_t instr;
    int rf1, rf2;
    if ((cmd >> 7) == 0) {
        instr.opcode = MOVI;
        instr.opnd.imm = cmd;
        return instr;
    }
    
    if (((cmd >> 6) & 1) == 1) {
        if ((cmd >> 2) == 0x30) {
            instr.opcode = IN;
        } else if ((cmd >> 2) == 0x31) {
            instr.opcode = OUT;
        } else {
            fprintf(stderr, "Bad inout: %x\n", (unsigned) cmd);
        }
        rf1 = cmd & 0x3;
        instr.opnd.rop = rf1;
        return instr;
    }

    rf1 = cmd & 0x3;
    rf2 = (cmd >> 2) & 0x3;
    instr.opnd.ops.rs = rf1;
    instr.opnd.ops.rd = rf2;

    switch ((cmd >> 4) & 0xF) {
        case 8: instr.opcode = ADD; return instr;
        case 9: instr.opcode = SUB; return instr;
        case 10: instr.opcode = MUL; return instr;
        case 11: instr.opcode = DIV; return instr;
    }
    
    fprintf(stderr, "Unrecognized insts: %x\n", (unsigned) cmd);
    abort();
}

const char *regnames[] = {"A", "B", "C", "D"};
const char *arithnames[] = {"ADD", "SUB", "MUL", "DIV"};

void print_instr(struct instr_t instr) {
    switch (instr.opcode) {
        case MOVI:
            printf("MOVI D, %d\n", instr.opnd.imm);
            break;
        case IN:
            printf("IN %s\n", regnames[instr.opnd.rop]);
            break;
        case OUT:
            printf("OUT %s\n", regnames[instr.opnd.rop]);
            break;
        case ADD:
        case SUB:
        case MUL:
        case DIV:
            printf("%s %s,%s\n", arithnames[instr.opcode - 8],
                                 regnames[instr.opnd.ops.rd],
                                 regnames[instr.opnd.ops.rs]);
            break;
        default:
            fprintf(stderr, "Unsupported insts\n");
            abort();
            break;
    }
}

int main() {
    unsigned command;
    while (scanf("%x", &command) == 1) {
        struct instr_t instr;
        unsigned char cmd = command & 0xFF;
        assert(cmd == command);
        instr = decode_command(cmd);
        print_instr(instr);
    }
    return 0;
}
