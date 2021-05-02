;	LABELS	|	INSTRACTIONS	|	OPERANDS

				global				_ft_strlen

				section				.text

_ft_strlen:
				xor					rax, rax
.loop:
				cmp					rdi, 0
				je					.exit
				cmp 				byte [rdi + rax], 0
				je 					.exit
				inc					rax
				jmp					.loop
.exit:
				ret
