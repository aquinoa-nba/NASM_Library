;	LABELS	|	INSTRACTIONS	|	OPERANDS

				global				_ft_strcpy

				section				.text

_ft_strcpy:
				push				rbx
				push				rcx
				xor					rcx, rcx
				xor					rbx, rbx
				mov					rax, rdi

.loop:
				mov					bl, byte [rsi + rcx]
				mov					byte [rdi + rcx], bl
				cmp					bl, 0
				je					.exit
				inc					rcx
				jmp					.loop

.exit:
				pop				rcx
				pop				rbx
				ret
