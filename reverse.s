	.file	"reverse.c"
	.intel_syntax noprefix
	.text
.Ltext0:
	.file 0 "/home/flip/workspace" "reverse.c"
	.p2align 4
	.globl	isStr
	.type	isStr, @function
isStr:
.LVL0:
.LFB38:
	.file 1 "reverse.c"
	.loc 1 33 1 view -0
	.cfi_startproc
	.loc 1 33 1 is_stmt 0 view .LVU1
	endbr64
	.loc 1 34 5 is_stmt 1 view .LVU2
	.loc 1 34 8 is_stmt 0 view .LVU3
	test	rdi, rdi
	je	.L6
	.loc 1 34 27 discriminator 1 view .LVU4
	movzx	eax, BYTE PTR [rdi]
	.loc 1 35 16 view .LVU5
	xor	edx, edx
	.loc 1 34 21 discriminator 1 view .LVU6
	test	al, al
	je	.L1
	add	rdi, 1
.LVL1:
	.loc 1 34 21 discriminator 1 view .LVU7
	jmp	.L3
.LVL2:
	.p2align 4,,10
	.p2align 3
.L11:
.LBB34:
.LBB35:
.LBB36:
	.loc 1 37 38 is_stmt 1 discriminator 2 view .LVU8
	.loc 1 37 28 discriminator 1 view .LVU9
	.loc 1 37 24 is_stmt 0 discriminator 1 view .LVU10
	movzx	eax, BYTE PTR [rdi]
	.loc 1 37 28 discriminator 1 view .LVU11
	add	rdi, 1
.LVL3:
	.loc 1 37 28 discriminator 1 view .LVU12
	test	al, al
	je	.L10
.LVL4:
.L3:
	.loc 1 38 9 is_stmt 1 view .LVU13
	.loc 1 38 13 is_stmt 0 view .LVU14
	and	eax, -33
	sub	eax, 65
	.loc 1 38 12 view .LVU15
	cmp	al, 25
	jbe	.L11
.LVL5:
.L6:
	.loc 1 38 12 view .LVU16
.LBE36:
.LBE35:
.LBE34:
	.loc 1 35 16 view .LVU17
	xor	edx, edx
.L1:
	.loc 1 43 1 view .LVU18
	mov	eax, edx
	ret
.LVL6:
	.p2align 4,,10
	.p2align 3
.L10:
.LBB38:
.LBB37:
	.loc 1 42 12 view .LVU19
	mov	edx, 1
.LBE37:
.LBE38:
	.loc 1 43 1 view .LVU20
	mov	eax, edx
	ret
	.cfi_endproc
.LFE38:
	.size	isStr, .-isStr
	.p2align 4
	.globl	reverse
	.type	reverse, @function
reverse:
.LVL7:
.LFB39:
	.loc 1 45 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 45 1 is_stmt 0 view .LVU22
	endbr64
	.loc 1 46 5 is_stmt 1 view .LVU23
	.loc 1 46 8 is_stmt 0 view .LVU24
	test	rdi, rdi
	je	.L20
	.loc 1 45 1 view .LVU25
	push	rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	mov	rbx, rdi
	.loc 1 47 5 is_stmt 1 view .LVU26
	.loc 1 47 13 is_stmt 0 view .LVU27
	call	strlen@PLT
.LVL8:
	.loc 1 48 5 is_stmt 1 view .LVU28
.LBB39:
	.loc 1 48 10 view .LVU29
	.loc 1 48 21 is_stmt 0 view .LVU30
	sub	eax, 1
.LVL9:
	.loc 1 48 34 is_stmt 1 discriminator 1 view .LVU31
	test	eax, eax
	jle	.L12
	cdqe
	.loc 1 48 34 is_stmt 0 discriminator 1 view .LVU32
	xor	edx, edx
.LVL10:
	.p2align 4,,10
	.p2align 3
.L14:
.LBB40:
	.loc 1 50 9 is_stmt 1 view .LVU33
	.loc 1 50 14 is_stmt 0 view .LVU34
	movzx	ecx, BYTE PTR [rbx+rdx]
.LVL11:
	.loc 1 51 9 is_stmt 1 view .LVU35
	.loc 1 51 21 is_stmt 0 view .LVU36
	movzx	esi, BYTE PTR [rbx+rax]
	.loc 1 51 16 view .LVU37
	mov	BYTE PTR [rbx+rdx], sil
	.loc 1 52 9 is_stmt 1 view .LVU38
.LBE40:
	.loc 1 48 34 is_stmt 0 discriminator 1 view .LVU39
	add	rdx, 1
.LVL12:
.LBB41:
	.loc 1 52 16 view .LVU40
	mov	BYTE PTR [rbx+rax], cl
.LBE41:
	.loc 1 48 42 is_stmt 1 discriminator 3 view .LVU41
.LVL13:
	.loc 1 48 34 discriminator 1 view .LVU42
	sub	rax, 1
	cmp	edx, eax
	jl	.L14
.LVL14:
.L12:
	.loc 1 48 34 is_stmt 0 discriminator 1 view .LVU43
.LBE39:
	.loc 1 54 1 view .LVU44
	pop	rbx
	.cfi_def_cfa_offset 8
.LVL15:
	.loc 1 54 1 view .LVU45
	ret
.LVL16:
	.p2align 4,,10
	.p2align 3
.L20:
	.cfi_restore 3
	.loc 1 54 1 view .LVU46
	ret
	.cfi_endproc
.LFE39:
	.size	reverse, .-reverse
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"Enter string (to %d symbols): "
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"\n"
.LC2:
	.string	"String not valid: %s\n"
.LC3:
	.string	"Invalid input."
.LC4:
	.string	"String valid: %s\n"
.LC5:
	.string	"Reversed string: %s\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB37:
	.loc 1 12 1 is_stmt 1 view -0
	.cfi_startproc
	endbr64
	push	rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
.LBB59:
.LBB60:
	.file 2 "/usr/include/x86_64-linux-gnu/bits/stdio2.h"
	.loc 2 86 10 is_stmt 0 view .LVU48
	mov	edx, 100
	mov	edi, 2
	lea	rsi, .LC0[rip]
.LBE60:
.LBE59:
	.loc 1 12 1 view .LVU49
	sub	rsp, 112
	.cfi_def_cfa_offset 128
	.loc 1 12 1 view .LVU50
	mov	rax, QWORD PTR fs:40
	mov	QWORD PTR 104[rsp], rax
	xor	eax, eax
	.loc 1 13 5 is_stmt 1 view .LVU51
	.loc 1 15 5 view .LVU52
.LVL17:
.LBB63:
.LBI59:
	.loc 2 84 1 view .LVU53
.LBB61:
	.loc 2 86 3 view .LVU54
.LBE61:
.LBE63:
.LBB64:
.LBB65:
	.loc 2 200 12 is_stmt 0 view .LVU55
	mov	rbx, rsp
.LBE65:
.LBE64:
.LBB67:
.LBB62:
	.loc 2 86 10 view .LVU56
	call	__printf_chk@PLT
.LVL18:
	.loc 2 86 10 view .LVU57
.LBE62:
.LBE67:
	.loc 1 16 5 is_stmt 1 view .LVU58
.LBB68:
.LBI64:
	.loc 2 196 1 view .LVU59
.LBB66:
	.loc 2 198 3 view .LVU60
	.loc 2 199 3 view .LVU61
	.loc 2 200 5 view .LVU62
	.loc 2 200 12 is_stmt 0 view .LVU63
	mov	rdx, QWORD PTR stdin[rip]
	mov	esi, 100
	mov	rdi, rbx
	call	fgets@PLT
.LVL19:
	.loc 2 200 12 view .LVU64
.LBE66:
.LBE68:
	.loc 1 16 8 discriminator 1 view .LVU65
	test	rax, rax
	je	.L24
	.loc 1 17 9 is_stmt 1 view .LVU66
	.loc 1 17 13 is_stmt 0 view .LVU67
	lea	rsi, .LC1[rip]
	mov	rdi, rbx
	call	strcspn@PLT
.LVL20:
	.loc 1 17 33 discriminator 1 view .LVU68
	mov	BYTE PTR [rsp+rax], 0
	.loc 1 19 9 is_stmt 1 view .LVU69
.LVL21:
.LBB69:
.LBI69:
	.loc 1 32 6 view .LVU70
.LBB70:
	.loc 1 34 5 view .LVU71
	.loc 1 34 27 is_stmt 0 discriminator 1 view .LVU72
	movzx	eax, BYTE PTR [rsp]
	.loc 1 34 21 discriminator 1 view .LVU73
	test	al, al
	je	.L25
	lea	rdx, 1[rsp]
	jmp	.L26
.LVL22:
	.p2align 4,,10
	.p2align 3
.L38:
.LBB71:
.LBB72:
	.loc 1 37 38 is_stmt 1 discriminator 2 view .LVU74
	.loc 1 37 28 discriminator 1 view .LVU75
	.loc 1 37 24 is_stmt 0 discriminator 1 view .LVU76
	movzx	eax, BYTE PTR [rdx]
	.loc 1 37 28 discriminator 1 view .LVU77
	add	rdx, 1
.LVL23:
	.loc 1 37 28 discriminator 1 view .LVU78
	test	al, al
	je	.L37
.LVL24:
.L26:
	.loc 1 38 9 is_stmt 1 view .LVU79
	.loc 1 38 13 is_stmt 0 view .LVU80
	and	eax, -33
	sub	eax, 65
	.loc 1 38 12 view .LVU81
	cmp	al, 25
	jbe	.L38
.LVL25:
.L25:
	.loc 1 38 12 view .LVU82
.LBE72:
.LBE71:
.LBE70:
.LBE69:
	.loc 1 24 13 is_stmt 1 view .LVU83
.LBB73:
.LBI73:
	.loc 2 84 1 view .LVU84
.LBB74:
	.loc 2 86 3 view .LVU85
	.loc 2 86 10 is_stmt 0 view .LVU86
	mov	rdx, rbx
	lea	rsi, .LC2[rip]
	mov	edi, 2
	xor	eax, eax
	call	__printf_chk@PLT
.LVL26:
.L28:
	.loc 2 86 10 view .LVU87
.LBE74:
.LBE73:
	.loc 1 29 5 is_stmt 1 view .LVU88
	.loc 1 30 1 is_stmt 0 view .LVU89
	mov	rax, QWORD PTR 104[rsp]
	sub	rax, QWORD PTR fs:40
	jne	.L39
	add	rsp, 112
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	xor	eax, eax
	pop	rbx
	.cfi_def_cfa_offset 8
	ret
.LVL27:
.L37:
	.cfi_restore_state
	.loc 1 20 13 is_stmt 1 view .LVU90
.LBB75:
.LBI75:
	.loc 2 84 1 view .LVU91
.LBB76:
	.loc 2 86 3 view .LVU92
	.loc 2 86 10 is_stmt 0 view .LVU93
	mov	rdx, rbx
	lea	rsi, .LC4[rip]
	mov	edi, 2
	xor	eax, eax
	call	__printf_chk@PLT
.LVL28:
	.loc 2 86 10 view .LVU94
.LBE76:
.LBE75:
	.loc 1 21 13 is_stmt 1 view .LVU95
	mov	rdi, rbx
	call	reverse
.LVL29:
	.loc 1 22 13 view .LVU96
.LBB77:
.LBI77:
	.loc 2 84 1 view .LVU97
.LBB78:
	.loc 2 86 3 view .LVU98
	.loc 2 86 10 is_stmt 0 view .LVU99
	mov	rdx, rbx
	mov	edi, 2
	xor	eax, eax
	lea	rsi, .LC5[rip]
	call	__printf_chk@PLT
.LVL30:
	.loc 2 86 10 view .LVU100
	jmp	.L28
.L24:
.LBE78:
.LBE77:
	.loc 1 27 9 is_stmt 1 view .LVU101
.LVL31:
.LBB79:
.LBI79:
	.loc 2 84 1 view .LVU102
.LBB80:
	.loc 2 86 3 view .LVU103
	.loc 2 86 10 is_stmt 0 view .LVU104
	lea	rdi, .LC3[rip]
	call	puts@PLT
.LVL32:
	.loc 2 86 10 view .LVU105
	jmp	.L28
.L39:
.LBE80:
.LBE79:
	.loc 1 30 1 view .LVU106
	call	__stack_chk_fail@PLT
.LVL33:
	.cfi_endproc
.LFE37:
	.size	main, .-main
	.text
.Letext0:
	.file 3 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h"
	.file 4 "/usr/include/x86_64-linux-gnu/bits/types.h"
	.file 5 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h"
	.file 6 "/usr/include/x86_64-linux-gnu/bits/types/FILE.h"
	.file 7 "/usr/include/string.h"
	.file 8 "/usr/include/x86_64-linux-gnu/bits/stdio2-decl.h"
	.file 9 "/usr/include/stdio.h"
	.file 10 "<built-in>"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x7f7
	.value	0x5
	.byte	0x1
	.byte	0x8
	.long	.Ldebug_abbrev0
	.uleb128 0x1d
	.long	.LASF62
	.byte	0x1d
	.long	.LASF0
	.long	.LASF1
	.long	.LLRL21
	.quad	0
	.long	.Ldebug_line0
	.uleb128 0x9
	.long	.LASF9
	.byte	0x3
	.byte	0xd6
	.byte	0x17
	.long	0x36
	.uleb128 0x4
	.byte	0x8
	.byte	0x7
	.long	.LASF2
	.uleb128 0x4
	.byte	0x4
	.byte	0x7
	.long	.LASF3
	.uleb128 0x1e
	.byte	0x8
	.uleb128 0x4
	.byte	0x1
	.byte	0x8
	.long	.LASF4
	.uleb128 0x4
	.byte	0x2
	.byte	0x7
	.long	.LASF5
	.uleb128 0x4
	.byte	0x1
	.byte	0x6
	.long	.LASF6
	.uleb128 0x4
	.byte	0x2
	.byte	0x5
	.long	.LASF7
	.uleb128 0x1f
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x4
	.byte	0x8
	.byte	0x5
	.long	.LASF8
	.uleb128 0x9
	.long	.LASF10
	.byte	0x4
	.byte	0x98
	.byte	0x19
	.long	0x69
	.uleb128 0x9
	.long	.LASF11
	.byte	0x4
	.byte	0x99
	.byte	0x1b
	.long	0x69
	.uleb128 0x6
	.long	0x92
	.uleb128 0xa
	.long	0x88
	.uleb128 0x4
	.byte	0x1
	.byte	0x6
	.long	.LASF12
	.uleb128 0x20
	.long	0x92
	.uleb128 0x21
	.long	.LASF63
	.byte	0xd8
	.byte	0x5
	.byte	0x31
	.byte	0x8
	.long	0x208
	.uleb128 0x1
	.long	.LASF13
	.byte	0x33
	.byte	0x7
	.long	0x62
	.byte	0
	.uleb128 0x1
	.long	.LASF14
	.byte	0x36
	.byte	0x9
	.long	0x88
	.byte	0x8
	.uleb128 0x1
	.long	.LASF15
	.byte	0x37
	.byte	0x9
	.long	0x88
	.byte	0x10
	.uleb128 0x1
	.long	.LASF16
	.byte	0x38
	.byte	0x9
	.long	0x88
	.byte	0x18
	.uleb128 0x1
	.long	.LASF17
	.byte	0x39
	.byte	0x9
	.long	0x88
	.byte	0x20
	.uleb128 0x1
	.long	.LASF18
	.byte	0x3a
	.byte	0x9
	.long	0x88
	.byte	0x28
	.uleb128 0x1
	.long	.LASF19
	.byte	0x3b
	.byte	0x9
	.long	0x88
	.byte	0x30
	.uleb128 0x1
	.long	.LASF20
	.byte	0x3c
	.byte	0x9
	.long	0x88
	.byte	0x38
	.uleb128 0x1
	.long	.LASF21
	.byte	0x3d
	.byte	0x9
	.long	0x88
	.byte	0x40
	.uleb128 0x1
	.long	.LASF22
	.byte	0x40
	.byte	0x9
	.long	0x88
	.byte	0x48
	.uleb128 0x1
	.long	.LASF23
	.byte	0x41
	.byte	0x9
	.long	0x88
	.byte	0x50
	.uleb128 0x1
	.long	.LASF24
	.byte	0x42
	.byte	0x9
	.long	0x88
	.byte	0x58
	.uleb128 0x1
	.long	.LASF25
	.byte	0x44
	.byte	0x16
	.long	0x221
	.byte	0x60
	.uleb128 0x1
	.long	.LASF26
	.byte	0x46
	.byte	0x14
	.long	0x226
	.byte	0x68
	.uleb128 0x1
	.long	.LASF27
	.byte	0x48
	.byte	0x7
	.long	0x62
	.byte	0x70
	.uleb128 0x1
	.long	.LASF28
	.byte	0x49
	.byte	0x7
	.long	0x62
	.byte	0x74
	.uleb128 0x1
	.long	.LASF29
	.byte	0x4a
	.byte	0xb
	.long	0x70
	.byte	0x78
	.uleb128 0x1
	.long	.LASF30
	.byte	0x4d
	.byte	0x12
	.long	0x4d
	.byte	0x80
	.uleb128 0x1
	.long	.LASF31
	.byte	0x4e
	.byte	0xf
	.long	0x54
	.byte	0x82
	.uleb128 0x1
	.long	.LASF32
	.byte	0x4f
	.byte	0x8
	.long	0x22b
	.byte	0x83
	.uleb128 0x1
	.long	.LASF33
	.byte	0x51
	.byte	0xf
	.long	0x23b
	.byte	0x88
	.uleb128 0x1
	.long	.LASF34
	.byte	0x59
	.byte	0xd
	.long	0x7c
	.byte	0x90
	.uleb128 0x1
	.long	.LASF35
	.byte	0x5b
	.byte	0x17
	.long	0x245
	.byte	0x98
	.uleb128 0x1
	.long	.LASF36
	.byte	0x5c
	.byte	0x19
	.long	0x24f
	.byte	0xa0
	.uleb128 0x1
	.long	.LASF37
	.byte	0x5d
	.byte	0x14
	.long	0x226
	.byte	0xa8
	.uleb128 0x1
	.long	.LASF38
	.byte	0x5e
	.byte	0x9
	.long	0x44
	.byte	0xb0
	.uleb128 0x1
	.long	.LASF39
	.byte	0x5f
	.byte	0xa
	.long	0x2a
	.byte	0xb8
	.uleb128 0x1
	.long	.LASF40
	.byte	0x60
	.byte	0x7
	.long	0x62
	.byte	0xc0
	.uleb128 0x1
	.long	.LASF41
	.byte	0x62
	.byte	0x8
	.long	0x254
	.byte	0xc4
	.byte	0
	.uleb128 0x9
	.long	.LASF42
	.byte	0x6
	.byte	0x7
	.byte	0x19
	.long	0x9e
	.uleb128 0x22
	.long	.LASF64
	.byte	0x5
	.byte	0x2b
	.byte	0xe
	.uleb128 0xb
	.long	.LASF43
	.uleb128 0x6
	.long	0x21c
	.uleb128 0x6
	.long	0x9e
	.uleb128 0xc
	.long	0x92
	.long	0x23b
	.uleb128 0xd
	.long	0x36
	.byte	0
	.byte	0
	.uleb128 0x6
	.long	0x214
	.uleb128 0xb
	.long	.LASF44
	.uleb128 0x6
	.long	0x240
	.uleb128 0xb
	.long	.LASF45
	.uleb128 0x6
	.long	0x24a
	.uleb128 0xc
	.long	0x92
	.long	0x264
	.uleb128 0xd
	.long	0x36
	.byte	0x13
	.byte	0
	.uleb128 0x6
	.long	0x99
	.uleb128 0xa
	.long	0x264
	.uleb128 0x23
	.long	.LASF53
	.byte	0x9
	.byte	0x95
	.byte	0xe
	.long	0x27a
	.uleb128 0x6
	.long	0x208
	.uleb128 0xa
	.long	0x27a
	.uleb128 0x12
	.long	.LASF46
	.value	0x197
	.long	0x2a
	.long	0x299
	.uleb128 0x3
	.long	0x264
	.byte	0
	.uleb128 0x13
	.long	.LASF47
	.byte	0x34
	.byte	0xc
	.long	0x62
	.long	0x2b4
	.uleb128 0x3
	.long	0x62
	.uleb128 0x3
	.long	0x264
	.uleb128 0x14
	.byte	0
	.uleb128 0x13
	.long	.LASF48
	.byte	0x6a
	.byte	0xe
	.long	0x88
	.long	0x2d8
	.uleb128 0x3
	.long	0x8d
	.uleb128 0x3
	.long	0x2a
	.uleb128 0x3
	.long	0x62
	.uleb128 0x3
	.long	0x27f
	.byte	0
	.uleb128 0x15
	.long	.LASF49
	.byte	0x64
	.long	.LASF48
	.long	0x88
	.long	0x2ff
	.uleb128 0x3
	.long	0x8d
	.uleb128 0x3
	.long	0x2a
	.uleb128 0x3
	.long	0x62
	.uleb128 0x3
	.long	0x27f
	.byte	0
	.uleb128 0x15
	.long	.LASF50
	.byte	0x60
	.long	.LASF51
	.long	0x88
	.long	0x321
	.uleb128 0x3
	.long	0x8d
	.uleb128 0x3
	.long	0x62
	.uleb128 0x3
	.long	0x27f
	.byte	0
	.uleb128 0x12
	.long	.LASF52
	.value	0x125
	.long	0x2a
	.long	0x33b
	.uleb128 0x3
	.long	0x264
	.uleb128 0x3
	.long	0x264
	.byte	0
	.uleb128 0x24
	.long	.LASF57
	.byte	0x1
	.byte	0x2c
	.byte	0x6
	.quad	.LFB39
	.quad	.LFE39-.LFB39
	.uleb128 0x1
	.byte	0x9c
	.long	0x3e5
	.uleb128 0x25
	.string	"str"
	.byte	0x1
	.byte	0x2c
	.byte	0x14
	.long	0x88
	.long	.LLST3
	.long	.LVUS3
	.uleb128 0xe
	.string	"n"
	.byte	0x2f
	.byte	0x9
	.long	0x62
	.long	.LLST4
	.long	.LVUS4
	.uleb128 0x26
	.quad	.LBB39
	.quad	.LBE39-.LBB39
	.long	0x3d0
	.uleb128 0xe
	.string	"i"
	.byte	0x30
	.byte	0xe
	.long	0x62
	.long	.LLST5
	.long	.LVUS5
	.uleb128 0xe
	.string	"j"
	.byte	0x30
	.byte	0x15
	.long	0x62
	.long	.LLST6
	.long	.LVUS6
	.uleb128 0x16
	.long	.LLRL7
	.uleb128 0x27
	.long	.LASF54
	.byte	0x1
	.byte	0x32
	.byte	0xe
	.long	0x92
	.long	.LLST8
	.long	.LVUS8
	.byte	0
	.byte	0
	.uleb128 0x7
	.quad	.LVL8
	.long	0x284
	.uleb128 0x2
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2
	.byte	0x73
	.sleb128 0
	.byte	0
	.byte	0
	.uleb128 0x28
	.long	.LASF55
	.byte	0x1
	.byte	0x20
	.byte	0x6
	.long	0x40f
	.byte	0x1
	.long	0x40f
	.uleb128 0xf
	.string	"str"
	.byte	0x1
	.byte	0x20
	.byte	0x18
	.long	0x264
	.uleb128 0x29
	.uleb128 0x17
	.string	"i"
	.byte	0x1
	.byte	0x25
	.byte	0xe
	.long	0x62
	.byte	0
	.byte	0
	.uleb128 0x4
	.byte	0x1
	.byte	0x2
	.long	.LASF56
	.uleb128 0x2a
	.long	.LASF58
	.byte	0x1
	.byte	0xb
	.byte	0x5
	.long	0x62
	.quad	.LFB37
	.quad	.LFE37-.LFB37
	.uleb128 0x1
	.byte	0x9c
	.long	0x70c
	.uleb128 0x2b
	.string	"str"
	.byte	0x1
	.byte	0xd
	.byte	0xa
	.long	0x70c
	.uleb128 0x3
	.byte	0x91
	.sleb128 -128
	.uleb128 0x18
	.long	0x759
	.quad	.LBI59
	.byte	.LVU53
	.long	.LLRL9
	.byte	0xf
	.byte	0x5
	.long	0x494
	.uleb128 0x5
	.long	0x767
	.long	.LLST10
	.long	.LVUS10
	.uleb128 0x7
	.quad	.LVL18
	.long	0x299
	.uleb128 0x2
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x1
	.byte	0x32
	.uleb128 0x2
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x9
	.byte	0x3
	.quad	.LC0
	.uleb128 0x2
	.uleb128 0x1
	.byte	0x51
	.uleb128 0x2
	.byte	0x8
	.byte	0x64
	.byte	0
	.byte	0
	.uleb128 0x18
	.long	0x71c
	.quad	.LBI64
	.byte	.LVU59
	.long	.LLRL11
	.byte	0x10
	.byte	0x9
	.long	0x4f9
	.uleb128 0x10
	.long	0x742
	.uleb128 0x5
	.long	0x736
	.long	.LLST12
	.long	.LVUS12
	.uleb128 0x5
	.long	0x72a
	.long	.LLST13
	.long	.LVUS13
	.uleb128 0x16
	.long	.LLRL11
	.uleb128 0x11
	.long	0x74d
	.long	.LLST14
	.long	.LVUS14
	.uleb128 0x7
	.quad	.LVL19
	.long	0x2ff
	.uleb128 0x2
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2
	.byte	0x73
	.sleb128 0
	.uleb128 0x2
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x2
	.byte	0x8
	.byte	0x64
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x8
	.long	0x3e5
	.quad	.LBI69
	.byte	.LVU70
	.quad	.LBB69
	.quad	.LBE69-.LBB69
	.byte	0x13
	.byte	0xd
	.long	0x56c
	.uleb128 0x5
	.long	0x3f6
	.long	.LLST15
	.long	.LVUS15
	.uleb128 0x2c
	.long	0x3e5
	.quad	.LBB71
	.quad	.LBE71-.LBB71
	.byte	0x1
	.byte	0x20
	.byte	0x6
	.uleb128 0x10
	.long	0x3f6
	.uleb128 0x19
	.long	0x402
	.quad	.LBB72
	.quad	.LBE72-.LBB72
	.uleb128 0x11
	.long	0x403
	.long	.LLST16
	.long	.LVUS16
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x8
	.long	0x759
	.quad	.LBI73
	.byte	.LVU84
	.quad	.LBB73
	.quad	.LBE73-.LBB73
	.byte	0x18
	.byte	0xd
	.long	0x5c4
	.uleb128 0x5
	.long	0x767
	.long	.LLST17
	.long	.LVUS17
	.uleb128 0x7
	.quad	.LVL26
	.long	0x299
	.uleb128 0x2
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x1
	.byte	0x32
	.uleb128 0x2
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x9
	.byte	0x3
	.quad	.LC2
	.uleb128 0x2
	.uleb128 0x1
	.byte	0x51
	.uleb128 0x2
	.byte	0x73
	.sleb128 0
	.byte	0
	.byte	0
	.uleb128 0x8
	.long	0x759
	.quad	.LBI75
	.byte	.LVU91
	.quad	.LBB75
	.quad	.LBE75-.LBB75
	.byte	0x14
	.byte	0xd
	.long	0x61c
	.uleb128 0x5
	.long	0x767
	.long	.LLST18
	.long	.LVUS18
	.uleb128 0x7
	.quad	.LVL28
	.long	0x299
	.uleb128 0x2
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x1
	.byte	0x32
	.uleb128 0x2
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x9
	.byte	0x3
	.quad	.LC4
	.uleb128 0x2
	.uleb128 0x1
	.byte	0x51
	.uleb128 0x2
	.byte	0x73
	.sleb128 0
	.byte	0
	.byte	0
	.uleb128 0x8
	.long	0x759
	.quad	.LBI77
	.byte	.LVU97
	.quad	.LBB77
	.quad	.LBE77-.LBB77
	.byte	0x16
	.byte	0xd
	.long	0x674
	.uleb128 0x5
	.long	0x767
	.long	.LLST19
	.long	.LVUS19
	.uleb128 0x7
	.quad	.LVL30
	.long	0x299
	.uleb128 0x2
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x1
	.byte	0x32
	.uleb128 0x2
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x9
	.byte	0x3
	.quad	.LC5
	.uleb128 0x2
	.uleb128 0x1
	.byte	0x51
	.uleb128 0x2
	.byte	0x73
	.sleb128 0
	.byte	0
	.byte	0
	.uleb128 0x8
	.long	0x759
	.quad	.LBI79
	.byte	.LVU102
	.quad	.LBB79
	.quad	.LBE79-.LBB79
	.byte	0x1b
	.byte	0x9
	.long	0x6c1
	.uleb128 0x5
	.long	0x767
	.long	.LLST20
	.long	.LVUS20
	.uleb128 0x7
	.quad	.LVL32
	.long	0x7e6
	.uleb128 0x2
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x9
	.byte	0x3
	.quad	.LC3
	.byte	0
	.byte	0
	.uleb128 0x1a
	.quad	.LVL20
	.long	0x321
	.long	0x6e6
	.uleb128 0x2
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2
	.byte	0x73
	.sleb128 0
	.uleb128 0x2
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x9
	.byte	0x3
	.quad	.LC1
	.byte	0
	.uleb128 0x1a
	.quad	.LVL29
	.long	0x33b
	.long	0x6fe
	.uleb128 0x2
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2
	.byte	0x73
	.sleb128 0
	.byte	0
	.uleb128 0x2d
	.quad	.LVL33
	.long	0x7f1
	.byte	0
	.uleb128 0xc
	.long	0x92
	.long	0x71c
	.uleb128 0xd
	.long	0x36
	.byte	0x63
	.byte	0
	.uleb128 0x1b
	.long	.LASF51
	.byte	0xc4
	.long	0x88
	.long	0x759
	.uleb128 0xf
	.string	"__s"
	.byte	0x2
	.byte	0xc4
	.byte	0x19
	.long	0x8d
	.uleb128 0xf
	.string	"__n"
	.byte	0x2
	.byte	0xc4
	.byte	0x22
	.long	0x62
	.uleb128 0x1c
	.long	.LASF59
	.byte	0xc4
	.byte	0x38
	.long	0x27f
	.uleb128 0x17
	.string	"sz"
	.byte	0x2
	.byte	0xc6
	.byte	0xa
	.long	0x2a
	.byte	0
	.uleb128 0x1b
	.long	.LASF60
	.byte	0x54
	.long	0x62
	.long	0x774
	.uleb128 0x1c
	.long	.LASF61
	.byte	0x54
	.byte	0x20
	.long	0x269
	.uleb128 0x14
	.byte	0
	.uleb128 0x2e
	.long	0x3e5
	.quad	.LFB38
	.quad	.LFE38-.LFB38
	.uleb128 0x1
	.byte	0x9c
	.long	0x7d2
	.uleb128 0x5
	.long	0x3f6
	.long	.LLST0
	.long	.LVUS0
	.uleb128 0x2f
	.long	0x3e5
	.long	.LLRL1
	.byte	0x1
	.byte	0x20
	.byte	0x6
	.uleb128 0x10
	.long	0x3f6
	.uleb128 0x19
	.long	0x402
	.quad	.LBB36
	.quad	.LBE36-.LBB36
	.uleb128 0x11
	.long	0x403
	.long	.LLST2
	.long	.LVUS2
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x30
	.uleb128 0x12
	.byte	0x9e
	.uleb128 0x10
	.byte	0x49
	.byte	0x6e
	.byte	0x76
	.byte	0x61
	.byte	0x6c
	.byte	0x69
	.byte	0x64
	.byte	0x20
	.byte	0x69
	.byte	0x6e
	.byte	0x70
	.byte	0x75
	.byte	0x74
	.byte	0x2e
	.byte	0xa
	.byte	0
	.uleb128 0x31
	.long	.LASF65
	.long	.LASF66
	.byte	0xa
	.byte	0
	.uleb128 0x32
	.long	.LASF67
	.long	.LASF67
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 5
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x49
	.byte	0
	.uleb128 0x2
	.uleb128 0x18
	.uleb128 0x7e
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x5
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.uleb128 0x2137
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0x21
	.sleb128 8
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x48
	.byte	0x1
	.uleb128 0x7d
	.uleb128 0x1
	.uleb128 0x7f
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x1d
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x52
	.uleb128 0x1
	.uleb128 0x2138
	.uleb128 0xb
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x58
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x59
	.uleb128 0xb
	.uleb128 0x57
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x37
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x13
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.uleb128 0x2137
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x5
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x34
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.uleb128 0x2137
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 7
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0x21
	.sleb128 15
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 8
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x14
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x15
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 8
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0x21
	.sleb128 14
	.uleb128 0x6e
	.uleb128 0xe
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x16
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x55
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x17
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x18
	.uleb128 0x1d
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x52
	.uleb128 0x1
	.uleb128 0x2138
	.uleb128 0xb
	.uleb128 0x55
	.uleb128 0x17
	.uleb128 0x58
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x59
	.uleb128 0xb
	.uleb128 0x57
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x19
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.byte	0
	.byte	0
	.uleb128 0x1a
	.uleb128 0x48
	.byte	0x1
	.uleb128 0x7d
	.uleb128 0x1
	.uleb128 0x7f
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1b
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 2
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x20
	.uleb128 0x21
	.sleb128 3
	.uleb128 0x34
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1c
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 2
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1d
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x1f
	.uleb128 0x1b
	.uleb128 0x1f
	.uleb128 0x55
	.uleb128 0x17
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x1e
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x1f
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x20
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x21
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x22
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x23
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x24
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7a
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x25
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.uleb128 0x2137
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x26
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x27
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.uleb128 0x2137
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x28
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x20
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x29
	.uleb128 0xb
	.byte	0x1
	.byte	0
	.byte	0
	.uleb128 0x2a
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7a
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x2b
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x2c
	.uleb128 0x1d
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x58
	.uleb128 0xb
	.uleb128 0x59
	.uleb128 0xb
	.uleb128 0x57
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x2d
	.uleb128 0x48
	.byte	0
	.uleb128 0x7d
	.uleb128 0x1
	.uleb128 0x7f
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x2e
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7a
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x2f
	.uleb128 0x1d
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x55
	.uleb128 0x17
	.uleb128 0x58
	.uleb128 0xb
	.uleb128 0x59
	.uleb128 0xb
	.uleb128 0x57
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x30
	.uleb128 0x36
	.byte	0
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x31
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x6e
	.uleb128 0xe
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x32
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x6e
	.uleb128 0xe
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_loclists,"",@progbits
	.long	.Ldebug_loc3-.Ldebug_loc2
.Ldebug_loc2:
	.value	0x5
	.byte	0x8
	.byte	0
	.long	0
.Ldebug_loc0:
.LVUS3:
	.uleb128 0
	.uleb128 .LVU28
	.uleb128 .LVU28
	.uleb128 .LVU45
	.uleb128 .LVU45
	.uleb128 .LVU46
	.uleb128 .LVU46
	.uleb128 0
.LLST3:
	.byte	0x6
	.quad	.LVL7
	.byte	0x4
	.uleb128 .LVL7-.LVL7
	.uleb128 .LVL8-1-.LVL7
	.uleb128 0x1
	.byte	0x55
	.byte	0x4
	.uleb128 .LVL8-1-.LVL7
	.uleb128 .LVL15-.LVL7
	.uleb128 0x1
	.byte	0x53
	.byte	0x4
	.uleb128 .LVL15-.LVL7
	.uleb128 .LVL16-.LVL7
	.uleb128 0x4
	.byte	0xa3
	.uleb128 0x1
	.byte	0x55
	.byte	0x9f
	.byte	0x4
	.uleb128 .LVL16-.LVL7
	.uleb128 .LFE39-.LVL7
	.uleb128 0x1
	.byte	0x55
	.byte	0
.LVUS4:
	.uleb128 .LVU28
	.uleb128 .LVU31
.LLST4:
	.byte	0x8
	.quad	.LVL8
	.uleb128 .LVL9-.LVL8
	.uleb128 0x1
	.byte	0x50
	.byte	0
.LVUS5:
	.uleb128 .LVU30
	.uleb128 .LVU33
	.uleb128 .LVU33
	.uleb128 .LVU40
	.uleb128 .LVU40
	.uleb128 .LVU42
.LLST5:
	.byte	0x6
	.quad	.LVL8
	.byte	0x4
	.uleb128 .LVL8-.LVL8
	.uleb128 .LVL10-.LVL8
	.uleb128 0x2
	.byte	0x30
	.byte	0x9f
	.byte	0x4
	.uleb128 .LVL10-.LVL8
	.uleb128 .LVL12-.LVL8
	.uleb128 0x1
	.byte	0x51
	.byte	0x4
	.uleb128 .LVL12-.LVL8
	.uleb128 .LVL13-.LVL8
	.uleb128 0x3
	.byte	0x71
	.sleb128 -1
	.byte	0x9f
	.byte	0
.LVUS6:
	.uleb128 .LVU31
	.uleb128 .LVU33
.LLST6:
	.byte	0x8
	.quad	.LVL9
	.uleb128 .LVL10-.LVL9
	.uleb128 0x1
	.byte	0x50
	.byte	0
.LVUS8:
	.uleb128 .LVU35
	.uleb128 .LVU43
.LLST8:
	.byte	0x8
	.quad	.LVL11
	.uleb128 .LVL14-.LVL11
	.uleb128 0x1
	.byte	0x52
	.byte	0
.LVUS10:
	.uleb128 .LVU53
	.uleb128 .LVU57
.LLST10:
	.byte	0x8
	.quad	.LVL17
	.uleb128 .LVL18-.LVL17
	.uleb128 0xa
	.byte	0x3
	.quad	.LC0
	.byte	0x9f
	.byte	0
.LVUS12:
	.uleb128 .LVU59
	.uleb128 .LVU64
.LLST12:
	.byte	0x8
	.quad	.LVL18
	.uleb128 .LVL19-.LVL18
	.uleb128 0x3
	.byte	0x8
	.byte	0x64
	.byte	0x9f
	.byte	0
.LVUS13:
	.uleb128 .LVU59
	.uleb128 .LVU64
.LLST13:
	.byte	0x8
	.quad	.LVL18
	.uleb128 .LVL19-.LVL18
	.uleb128 0x1
	.byte	0x53
	.byte	0
.LVUS14:
	.uleb128 .LVU61
	.uleb128 .LVU64
.LLST14:
	.byte	0x8
	.quad	.LVL18
	.uleb128 .LVL19-.LVL18
	.uleb128 0x3
	.byte	0x8
	.byte	0x64
	.byte	0x9f
	.byte	0
.LVUS15:
	.uleb128 .LVU70
	.uleb128 .LVU82
.LLST15:
	.byte	0x8
	.quad	.LVL21
	.uleb128 .LVL25-.LVL21
	.uleb128 0x1
	.byte	0x53
	.byte	0
.LVUS16:
	.uleb128 .LVU74
	.uleb128 .LVU75
	.uleb128 .LVU75
	.uleb128 .LVU78
	.uleb128 .LVU78
	.uleb128 .LVU82
.LLST16:
	.byte	0x6
	.quad	.LVL22
	.byte	0x4
	.uleb128 .LVL22-.LVL22
	.uleb128 .LVL22-.LVL22
	.uleb128 0x7
	.byte	0x77
	.sleb128 0
	.byte	0x20
	.byte	0x71
	.sleb128 0
	.byte	0x22
	.byte	0x9f
	.byte	0x4
	.uleb128 .LVL22-.LVL22
	.uleb128 .LVL23-.LVL22
	.uleb128 0x6
	.byte	0x71
	.sleb128 0
	.byte	0x77
	.sleb128 0
	.byte	0x1c
	.byte	0x9f
	.byte	0x4
	.uleb128 .LVL23-.LVL22
	.uleb128 .LVL25-.LVL22
	.uleb128 0x7
	.byte	0x77
	.sleb128 0
	.byte	0x20
	.byte	0x71
	.sleb128 0
	.byte	0x22
	.byte	0x9f
	.byte	0
.LVUS17:
	.uleb128 .LVU84
	.uleb128 .LVU87
.LLST17:
	.byte	0x8
	.quad	.LVL25
	.uleb128 .LVL26-.LVL25
	.uleb128 0xa
	.byte	0x3
	.quad	.LC2
	.byte	0x9f
	.byte	0
.LVUS18:
	.uleb128 .LVU91
	.uleb128 .LVU94
.LLST18:
	.byte	0x8
	.quad	.LVL27
	.uleb128 .LVL28-.LVL27
	.uleb128 0xa
	.byte	0x3
	.quad	.LC4
	.byte	0x9f
	.byte	0
.LVUS19:
	.uleb128 .LVU97
	.uleb128 .LVU100
.LLST19:
	.byte	0x8
	.quad	.LVL29
	.uleb128 .LVL30-.LVL29
	.uleb128 0xa
	.byte	0x3
	.quad	.LC5
	.byte	0x9f
	.byte	0
.LVUS20:
	.uleb128 .LVU102
	.uleb128 .LVU105
.LLST20:
	.byte	0x8
	.quad	.LVL31
	.uleb128 .LVL32-.LVL31
	.uleb128 0x6
	.byte	0xa0
	.long	.Ldebug_info0+2002
	.sleb128 0
	.byte	0
.LVUS0:
	.uleb128 0
	.uleb128 .LVU7
	.uleb128 .LVU7
	.uleb128 .LVU8
	.uleb128 .LVU8
	.uleb128 0
.LLST0:
	.byte	0x6
	.quad	.LVL0
	.byte	0x4
	.uleb128 .LVL0-.LVL0
	.uleb128 .LVL1-.LVL0
	.uleb128 0x1
	.byte	0x55
	.byte	0x4
	.uleb128 .LVL1-.LVL0
	.uleb128 .LVL2-.LVL0
	.uleb128 0x3
	.byte	0x75
	.sleb128 -1
	.byte	0x9f
	.byte	0x4
	.uleb128 .LVL2-.LVL0
	.uleb128 .LFE38-.LVL0
	.uleb128 0x4
	.byte	0xa3
	.uleb128 0x1
	.byte	0x55
	.byte	0x9f
	.byte	0
.LVUS2:
	.uleb128 .LVU8
	.uleb128 .LVU9
	.uleb128 .LVU9
	.uleb128 .LVU12
	.uleb128 .LVU12
	.uleb128 .LVU16
	.uleb128 .LVU19
	.uleb128 0
.LLST2:
	.byte	0x6
	.quad	.LVL2
	.byte	0x4
	.uleb128 .LVL2-.LVL2
	.uleb128 .LVL2-.LVL2
	.uleb128 0x8
	.byte	0xa3
	.uleb128 0x1
	.byte	0x55
	.byte	0x20
	.byte	0x75
	.sleb128 0
	.byte	0x22
	.byte	0x9f
	.byte	0x4
	.uleb128 .LVL2-.LVL2
	.uleb128 .LVL3-.LVL2
	.uleb128 0x7
	.byte	0x75
	.sleb128 0
	.byte	0xa3
	.uleb128 0x1
	.byte	0x55
	.byte	0x1c
	.byte	0x9f
	.byte	0x4
	.uleb128 .LVL3-.LVL2
	.uleb128 .LVL5-.LVL2
	.uleb128 0x8
	.byte	0xa3
	.uleb128 0x1
	.byte	0x55
	.byte	0x20
	.byte	0x75
	.sleb128 0
	.byte	0x22
	.byte	0x9f
	.byte	0x4
	.uleb128 .LVL6-.LVL2
	.uleb128 .LFE38-.LVL2
	.uleb128 0x8
	.byte	0xa3
	.uleb128 0x1
	.byte	0x55
	.byte	0x20
	.byte	0x75
	.sleb128 0
	.byte	0x22
	.byte	0x9f
	.byte	0
.Ldebug_loc3:
	.section	.debug_aranges,"",@progbits
	.long	0x3c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x8
	.byte	0
	.value	0
	.value	0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	.LFB37
	.quad	.LFE37-.LFB37
	.quad	0
	.quad	0
	.section	.debug_rnglists,"",@progbits
.Ldebug_ranges0:
	.long	.Ldebug_ranges3-.Ldebug_ranges2
.Ldebug_ranges2:
	.value	0x5
	.byte	0x8
	.byte	0
	.long	0
.LLRL1:
	.byte	0x5
	.quad	.LBB34
	.byte	0x4
	.uleb128 .LBB34-.LBB34
	.uleb128 .LBE34-.LBB34
	.byte	0x4
	.uleb128 .LBB38-.LBB34
	.uleb128 .LBE38-.LBB34
	.byte	0
.LLRL7:
	.byte	0x5
	.quad	.LBB40
	.byte	0x4
	.uleb128 .LBB40-.LBB40
	.uleb128 .LBE40-.LBB40
	.byte	0x4
	.uleb128 .LBB41-.LBB40
	.uleb128 .LBE41-.LBB40
	.byte	0
.LLRL9:
	.byte	0x5
	.quad	.LBB59
	.byte	0x4
	.uleb128 .LBB59-.LBB59
	.uleb128 .LBE59-.LBB59
	.byte	0x4
	.uleb128 .LBB63-.LBB59
	.uleb128 .LBE63-.LBB59
	.byte	0x4
	.uleb128 .LBB67-.LBB59
	.uleb128 .LBE67-.LBB59
	.byte	0
.LLRL11:
	.byte	0x5
	.quad	.LBB64
	.byte	0x4
	.uleb128 .LBB64-.LBB64
	.uleb128 .LBE64-.LBB64
	.byte	0x4
	.uleb128 .LBB68-.LBB64
	.uleb128 .LBE68-.LBB64
	.byte	0
.LLRL21:
	.byte	0x7
	.quad	.Ltext0
	.uleb128 .Letext0-.Ltext0
	.byte	0x7
	.quad	.LFB37
	.uleb128 .LFE37-.LFB37
	.byte	0
.Ldebug_ranges3:
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF60:
	.string	"printf"
.LASF10:
	.string	"__off_t"
.LASF14:
	.string	"_IO_read_ptr"
.LASF26:
	.string	"_chain"
.LASF9:
	.string	"size_t"
.LASF32:
	.string	"_shortbuf"
.LASF20:
	.string	"_IO_buf_base"
.LASF35:
	.string	"_codecvt"
.LASF6:
	.string	"signed char"
.LASF27:
	.string	"_fileno"
.LASF15:
	.string	"_IO_read_end"
.LASF8:
	.string	"long int"
.LASF13:
	.string	"_flags"
.LASF21:
	.string	"_IO_buf_end"
.LASF30:
	.string	"_cur_column"
.LASF44:
	.string	"_IO_codecvt"
.LASF48:
	.string	"__fgets_chk"
.LASF47:
	.string	"__printf_chk"
.LASF29:
	.string	"_old_offset"
.LASF34:
	.string	"_offset"
.LASF55:
	.string	"isStr"
.LASF54:
	.string	"temp"
.LASF43:
	.string	"_IO_marker"
.LASF53:
	.string	"stdin"
.LASF3:
	.string	"unsigned int"
.LASF38:
	.string	"_freeres_buf"
.LASF46:
	.string	"strlen"
.LASF59:
	.string	"__stream"
.LASF2:
	.string	"long unsigned int"
.LASF18:
	.string	"_IO_write_ptr"
.LASF57:
	.string	"reverse"
.LASF52:
	.string	"strcspn"
.LASF5:
	.string	"short unsigned int"
.LASF22:
	.string	"_IO_save_base"
.LASF33:
	.string	"_lock"
.LASF28:
	.string	"_flags2"
.LASF40:
	.string	"_mode"
.LASF51:
	.string	"fgets"
.LASF66:
	.string	"__builtin_puts"
.LASF65:
	.string	"puts"
.LASF49:
	.string	"__fgets_chk_warn"
.LASF19:
	.string	"_IO_write_end"
.LASF64:
	.string	"_IO_lock_t"
.LASF63:
	.string	"_IO_FILE"
.LASF25:
	.string	"_markers"
.LASF56:
	.string	"_Bool"
.LASF4:
	.string	"unsigned char"
.LASF7:
	.string	"short int"
.LASF45:
	.string	"_IO_wide_data"
.LASF50:
	.string	"__fgets_alias"
.LASF31:
	.string	"_vtable_offset"
.LASF42:
	.string	"FILE"
.LASF67:
	.string	"__stack_chk_fail"
.LASF12:
	.string	"char"
.LASF11:
	.string	"__off64_t"
.LASF16:
	.string	"_IO_read_base"
.LASF24:
	.string	"_IO_save_end"
.LASF61:
	.string	"__fmt"
.LASF39:
	.string	"__pad5"
.LASF41:
	.string	"_unused2"
.LASF62:
	.string	"GNU C17 13.3.0 -masm=intel -mtune=generic -march=x86-64 -g -O2 -fasynchronous-unwind-tables -fstack-protector-strong -fstack-clash-protection -fcf-protection"
.LASF23:
	.string	"_IO_backup_base"
.LASF37:
	.string	"_freeres_list"
.LASF36:
	.string	"_wide_data"
.LASF58:
	.string	"main"
.LASF17:
	.string	"_IO_write_base"
	.section	.debug_line_str,"MS",@progbits,1
.LASF1:
	.string	"/home/flip/workspace"
.LASF0:
	.string	"reverse.c"
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
