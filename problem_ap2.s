	.file	"problem_ap2.c"
	.intel_syntax noprefix
	.text
	.p2align 4
	.globl	is_prime
	.type	is_prime, @function
is_prime:
	.cfi_startproc
	xor	eax, eax
	cmp	edi, 1
	jbe	.L1
	mov	eax, 1
	cmp	edi, 3
	jbe	.L1
	xor	eax, eax
	test	dil, 1
	je	.L1
	cmp	edi, 8
	jbe	.L7
	mov	ecx, 3
	jmp	.L3
	.p2align 5
	.p2align 4,,10
	.p2align 3
.L12:
	add	ecx, 2
	mov	eax, ecx
	imul	eax, ecx
	cmp	edi, eax
	jb	.L7
.L3:
	mov	eax, edi
	xor	edx, edx
	div	ecx
	test	edx, edx
	jne	.L12
	xor	eax, eax
.L1:
	ret
.L7:
	mov	eax, 1
	ret
	.cfi_endproc
.LFE0:
	.size	is_prime, .-is_prime
	.ident	"GCC: (GNU) 14.2.1 20250207"
	.section	.note.GNU-stack,"",@progbits
