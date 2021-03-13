section .text
	global _ft_strcmp

_ft_strcmp:
	mov r10, -1
	jmp _loop

_loop:
	inc r10
	cmp byte[rdi + r10], 0
	je _yes_done
	cmp byte[rsi + r10], 0
	je _yes_done
	mov cl, byte[rdi + r10]
	cmp cl, byte[rsi + r10]
	je _loop
	jmp _no_done

_yes_done:
	mov rax, 0
	ret

_no_done:
	mov cl, byte[rdi + r10]
	mov byte[r9], cl
	mov cl, byte[rsi + r10]
	mov byte[r8], cl
	sub r9, r8
	;mov rax, r9
	ret
