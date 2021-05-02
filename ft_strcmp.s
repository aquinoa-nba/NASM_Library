;	LABELS	|	INSTRACTIONS	|	OPERANDS

global			_ft_strcmp

_ft_strcmp:
				xor					rax, rax
				push				rbx
				xor					rbx, rbx
				push				rcx
				xor					rcx, rcx
.loop:
				mov					bl, byte [rdi + rax]
				mov					cl, byte [rsi + rax]
				cmp					bl, 0
				je					.exit
				cmp					cl, 0
				je					.exit
				cmp					bl, cl
				jne					.exit
				inc					rax
				jmp					.loop

.exit:
				sub					rbx, rcx
				mov					rax, rbx
				pop					rcx
				pop					rbx
				ret
