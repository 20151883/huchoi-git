section .text
	global _ft_write
	extern ___error
_ft_write:
	mov rax, 0x2000004
	syscall
	jc _err
	ret
_err:
	push rax
	call ___error
	pop r10
	mov [rax], r10
	mov rax, -1
	ret
