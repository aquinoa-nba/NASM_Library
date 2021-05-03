NAME		=		libasm.a

SRCS		=		ft_strlen.s ft_strcmp.s ft_write.s ft_strcpy.s ft_read.s ft_strdup.s

CC			=		gcc
CFLAGS		=	 	-Wall -Werror -Wextra
ASM_CC		=		nasm -f
FORMAT		=		macho64

OBJS_DIR	=		.obj

OBJS		=	 	$(addprefix $(OBJS_DIR)/, $(patsubst %.s, %.o, $(SRCS)))

all:				$(NAME)

$(NAME):			$(OBJS)
					@printf "$(LIGHT_PURPLE)$(BOLD)$(NAME) $(NO_COLOR)–– $(LIGHT_PURPLE)$(BOLD)[Success compiling]        $(NO_COLOR)\n"
					@ar rc $@ $(OBJS)


$(OBJS_DIR)/%.o:	%.s
					@test -d $(OBJS_DIR) || mkdir $(OBJS_DIR)
					@printf "$(GREEN)$(BOLD)Compilation $(UNDER_LINE)$(YELLOW)$<$(NO_COLOR)  $(BOLD)–– $(RED)[KO]        $(NO_COLOR)\r"
					@$(ASM_CC) $(FORMAT) $< -o $@
					@printf "$(GREEN)$(BOLD)Compilation $(UNDER_LINE)$(YELLOW)$<$(NO_COLOR)  $(BOLD)–– $(GREEN)[OK]$(NO_COLOR)\n"

test: 				main.c $(OBJ)
					@$(CC) $(FLAGS) main.c -L. -lasm -o test_asm
					@./test_asm

clean:
					@rm -f $(OBJS)
					@rm -rf $(OBJS_DIR)

fclean:				clean
					@rm -f $(NAME)
					@rm -f test_asm file
					@printf "$(UNDER_LINE)$(BOLD)$(NAME)$(NO_COLOR) $(LIGHT_RED)deleted$(NO_COLOR)\n"


re:					fclean all

################
##   COLORS   ##
################

UNDER_LINE	= \033[4m
BOLD	 	= \033[1m

NO_COLOR 	= \033[0m
BLACK	 	= \033[0;30m
RED 	 	= \033[0;31m
GREEN 	 	= \033[0;32m
BROWN 	 	= \033[0;33m
BLUE 		= \033[0;34m
PURPLE 	 	= \033[0;35m
CYAN 	 	= \033[0;36m
LIGHT_GRAY	= \033[0;37m

DARK_GRAY	= \033[1;30m
LIGHT_RED	= \033[1;31m
LIGHT_GREEN	= \033[1;32m
YELLOW 		= \033[1;33m
LIGHT_BLUE	= \033[1;34m
LIGHT_PURPLE= \033[1;35m
LIGHT_CYAN	= \033[1;36m
WHITE 		= \033[1;37m