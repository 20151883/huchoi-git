section .text
	global _ft_strcmp

_ft_strcmp:
	xor rax, rax
	xor rcx, rcx
	xor rdx, rdx
	mov r10, 0
	jmp _loop

_loop:
	mov cl, byte[rdi + r10]
	mov dl, byte[rsi + r10]
	cmp cl, dl
	jne _done
	cmp cl, 0
	je _done
	inc r10
	jmp _loop

_done:
	sub cl, dl
	xor rax, rax
	mov al, cl
	ret
