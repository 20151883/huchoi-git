section .text
	global _ft_test

_ft_test:
	mov rcx, 5
	push rcx
	pop rax
	ret
