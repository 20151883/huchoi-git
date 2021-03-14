section .text
	global _ft_strcpy
_ft_strcpy:
	;rdi rsi
	xor r10, r10
	mov rax, rdi
	jmp _loop
_loop:
	mov cl, byte[rsi + r10]
	mov byte[rdi + r10], cl
	cmp byte[rsi + r10], 0
	je _done
	inc r10
	jmp _loop
_done:
	ret
