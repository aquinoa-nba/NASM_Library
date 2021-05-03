#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *s);

int		ft_strcmp(const char *s1, const char *s2);

ssize_t ft_write(int fd, const void *buf, size_t count);

ssize_t ft_read(int fd, const void *buf, size_t count);

char	*ft_strcpy(char * dst, const char * src);

char	*ft_strdup(const char *s1);

int	main(void)
{
	char	*str_1;
	char	*str_2;
	int		res_1;
	int		res_2;
	int		fd;

																		printf("|----\033[1;31m test for ft_read \033[0m----|\n\n");

	char	*buf;

	buf = malloc(1024);
	res_1 = read(0, buf, 1024);
	buf[res_1 - 1] = '\0';
	printf("\033[1;32m read from stdin -> \033[0m \033[1;31m buf \033[0m: %s | \033[1;31m returned \033[0m: %d\n", buf, res_1);
	buf = malloc(1024);
	res_2 = ft_read(0, buf, 1024);
	buf[res_2 - 1] = '\0';
	printf("\033[1;33m ft_read from stdin -> \033[0m \033[1;31m buf \033[0m: %s | \033[1;31m returned \033[0m: %d\n\n", buf, res_2);

	fd = open("file_for_read", O_CREAT | O_RDWR, 0644);

	buf = malloc(1024);
	res_1 = read(fd, buf, 1024);
	close(fd);
	printf("\033[1;32m read from file -> \033[1;31m buf \033[0m: %s |\033[1;31m returned \033[0m: %d\n", buf, res_1);
	fd = open("file_for_ft_read", O_CREAT | O_RDWR, 0644);
	buf = malloc(1024);
	res_2 = ft_read(fd, buf, 1024);
	close(fd);
	printf("\033[1;33m ft_read from file -> \033[1;31m buf \033[0m: %s |\033[1;31m returned \033[0m: %d\n\n", buf, res_2);

	buf = malloc(1024);
	res_1 = read(-1, buf, 1024);
	printf("\033[1;32m read from invalid fd -> \033[0m %d \n", res_1);
	printf("\033[1;32m errno -> \033[0m %d \n", errno);
	printf(" %s \n\n", strerror(errno));
	res_2 = ft_read(-1, buf, 1024);
	printf("\033[1;33m ft_read from invalid fd -> \033[0m %d \n", res_2);
	printf("\033[1;33m errno -> \033[0m %d \n", errno);
	printf(" %s \n\n", strerror(errno));

																		printf("|----\033[1;31m test for ft_strcpy \033[0m----|\n\n");

	char	*dst;

	dst = malloc(1024);
	printf("\033[0;32m dst -> %s\033[0m\n", dst);
	str_1 = strcpy(dst, "An assembly (or assembler) language, often abbreviated\
asm, is a low-level programming language for a computer, \
or other programmable device, in which there is a very \
strong (but often not one-to-one) correspondence between \
the language and the architecture’s machine code instructions. \
Each assembly language is specific to a particular computer \
architecture. In contrast, most high-level programming \
languages are generally portable across multiple architectures \
but require interpreting or compiling. Assembly language \
may also be called symbolic machine code.");
	printf("\033[0;32m strcpy -> \033[0m%s\n\n", dst);

	printf("\033[0;32m dst -> \033[0m%s\n", dst);
	str_1 = strcpy(dst, "");
	printf("\033[0;32m strcpy -> \033[0m%s\n\n", dst);

	// dst = malloc(1024);
	printf("\033[0;33m dst -> \033[0m%s\n", dst);
	ft_strcpy(dst, "An assembly (or assembler) language, often abbreviated \
asm, is a low-level programming language for a computer, \
or other programmable device, in which there is a very \
strong (but often not one-to-one) correspondence between \
the language and the architecture’s machine code instructions. \
Each assembly language is specific to a particular computer \
architecture. In contrast, most high-level programming \
languages are generally portable across multiple architectures \
but require interpreting or compiling. Assembly language \
may also be called symbolic machine code.");
	printf("\033[0;33m ft_strcpy -> \033[0m%s\n\n", dst);

	printf("\033[0;33m dst -> \033[0m%s\n", dst);
	ft_strcpy(dst, "");
	printf("\033[0;33m ft_strcpy -> \033[0m%s\n\n", dst);

	printf("/----------------------\\\n");
	printf("|\033[1;32m  strlen  \033[0m|\033[1;33m ft_strlen \033[0m|\n");
	printf("|----------|-----------|\n");
	printf("|     %zu    |     %zu     |\n", strlen(""), ft_strlen(""));
	str_1 = "An assembly (or assembler) language, often abbreviated asm, is a low-level programming \
			language for a computer, or other programmable device, in which there is a very strong \
			(but often not one-to-one) correspondence between the language and the architecture’s \
			machine code instructions. Each assembly language is specific to a particular computer \
			architecture. In contrast, most high-level programming languages are generally portable \
			across multiple architectures but require interpreting or compiling. Assembly language \
			may also be called symbolic machine code.";
	printf("|    %zu   |    %zu    |\n", strlen(str_1), ft_strlen(str_1));
	printf("|----------|-----------|\n");
	printf("|\033[1;32m  strcmp  \033[0m|\033[1;33m ft_strcmp \033[0m|\n");
	str_1="";
	str_2="";
	printf("|----------|-----------|\n");
	printf("|    %d     |    %d      |\n", strcmp(str_1, str_2), ft_strcmp(str_1, str_2));
	str_1="";
	str_2="0";
	printf("|   %d    |   %d     |\n", strcmp(str_1, str_2), ft_strcmp(str_1, str_2));
	str_1="0";
	str_2="";
	printf("|    %d    |    %d     |\n", strcmp(str_1, str_2), ft_strcmp(str_1, str_2));
	printf("\\----------------------/\n\n");

	printf("/----------------------------\\\n");
	write(1, "|\033[1;32m   write   -> \033[0m| " , 28);
	res_1 = write(1, "Hello world", 11);
	write(1, " |\n", 3);
	printf("|\033[1;32m  sys ret  -> \033[0m|     %d      |\n", res_1);
	printf("|--------------|-------------|\n");
	write(1, "|\033[1;33m ft_write  -> \033[0m| ", 28);
	res_2 = ft_write(1, "Hello world", 11);
	write(1, " |\n", 3);
	printf("|\033[1;33m  my ret   -> \033[0m|     %d      |\n", res_2);
	printf("|--------------|-------------|\n");

	fd = open("file", O_CREAT | O_RDWR, 0644);

	write(1, "|\033[1;32m   write   -> \033[0m| " , 28);
	res_1 = write(fd, "This line is written with \"write\"\n", 34);
	// close(fd);
	write(1, "            |\n", 14);
	printf("|\033[1;32m  sys ret  -> \033[0m|     %d      |\n", res_1);
	printf("|--------------|-------------|\n");
	// fd = open("file", O_CREAT | O_RDWR, 0644);
	write(1, "|\033[1;33m ft_write  -> \033[0m| ", 28);
	res_2 = ft_write(fd, "This line is written with \"ft_write\"\n", 37);
	close(fd);
	write(1, "            |\n", 14);
	printf("|\033[1;33m  my ret   -> \033[0m|     %d      |\n", res_2);
	printf("|--------------|-------------|\n");

	res_1 = write(-1, "Hello", 5);
	printf("|\033[1;32m  sys ret  -> \033[0m|     %d      |\n", res_1);
	printf("|\033[1;32m sys errno -> \033[0m|      %d      |\n", errno);
	printf("|--------------|-------------|\n");
	printf("|     %s    |\n", strerror(errno));
	printf("|--------------|-------------|\n");
	res_2 = ft_write(-1, "Hello", 5);
	printf("|\033[1;33m   my ret  -> \033[0m|     %d      |\n", res_2);
	printf("|\033[1;33m  my errno -> \033[0m|      %d      |\n", errno);
	printf("|--------------|-------------|\n");
	printf("|     %s    |\n", strerror(errno));
	printf("\\----------------------------/\n\n");

																		printf("|----\033[1;31m test for ft_strdup \033[0m----|\n\n");

	char	*dup_str;

	dup_str = strdup("");
	printf("\033[1;32m strdup -> \033[0m %s\n", dup_str);

	dup_str = ft_strdup("");
	printf("\033[1;33m ft_strdup -> \033[0m %s\n\n", dup_str);

	dup_str = strdup("An assembly (or assembler) language, often abbreviated asm, is a low-level programming \
language for a computer, or other programmable device, in which there is a very strong \
(but often not one-to-one) correspondence between the language and the architecture’s \
machine code instructions. Each assembly language is specific to a particular computer \
architecture. In contrast, most high-level programming languages are generally portable \
across multiple architectures but require interpreting or compiling. Assembly language \
may also be called symbolic machine code.");
	printf("\033[1;32m   strdup  -> \033[0m %s\n", dup_str);

	dup_str = ft_strdup("An assembly (or assembler) language, often abbreviated asm, is a low-level programming \
language for a computer, or other programmable device, in which there is a very strong \
(but often not one-to-one) correspondence between the language and the architecture’s \
machine code instructions. Each assembly language is specific to a particular computer \
architecture. In contrast, most high-level programming languages are generally portable \
across multiple architectures but require interpreting or compiling. Assembly language \
may also be called symbolic machine code.");
	printf("\033[1;33m ft_strdup -> \033[0m %s\n", dup_str);
}
