;	LABELS	|	INSTRACTIONS	|	OPERANDS
				extern				_malloc

				extern				_ft_strlen

				extern				_ft_strcpy

				global				_ft_strdup

				section				.text

_ft_strdup:
				push				rdi
				call				_ft_strlen
				mov					rdi, rax
				inc					rdi
				call				_malloc
				jc					.exit
				pop					rdi
				mov					rsi, rdi
				mov					rdi, rax
				call				_ft_strcpy
				jmp					.exit

.exit:
				ret
