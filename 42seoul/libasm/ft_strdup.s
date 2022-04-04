section .text
	global _ft_strdup
	extern _malloc
	extern _ft_strlen
	extern _ft_strcpy

_ft_strdup:
	push rdi
	xor rax, rax
	call _ft_strlen
	inc rax
	xor rdi, rdi
	mov cl, al
	mov dil, cl
	call _malloc
	cmp rax, 0
	je errr
	mov rdi, rax
	pop rsi
	call _ft_strcpy
	ret

errr:
	ret