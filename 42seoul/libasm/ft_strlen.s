section .text
	global _ft_strlen
_ft_strlen:
	mov rax, 0
	jmp _loop
_loop:
	cmp byte[rdi + rax], 0
	je _done
	inc rax
	jmp _loop
_done:
	ret
