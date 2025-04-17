    .intel_syntax noprefix
	.text
	.p2align 4
	.globl	is_prime
	.type	is_prime, @function
is_prime:
    mov    eax, 0
    cmp    edi, 1
    jbe    composite
    cmp    edi, 3
    jbe    prime
    test   dil, 1
    je     composite
    mov    ecx, 2

loop:
   mov    ecx, 3
   jmp    midloop
loop2:
    mov   eax, ecx
    imul  eax, ecx
    cmp   eax, edi
    ja    prime
	add	  ecx, 2
    mov	  eax, ecx
	imul  eax, ecx
	cmp	  edi, eax
	je    composite
midloop:	
	mov	   eax, edi
	xor	   edx, edx
	div	   ecx
	test   edx, edx
    je     composite
	jmp    prime
	xor	   eax, eax
    jne    loop

composite:
    mov     eax, 0
    ret

prime:
    mov     eax, 1
    ret
