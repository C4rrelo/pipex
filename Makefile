NAME		=	pipex

NAME_BONUS	=	pipexbonus

FILES		= pipex.c utils.c

BONUS_FILES	=	./bonus/pipex_bonus.c\
				./bonus/get_next_line.c\
				./bonus/utils1.c\

OBJS		=	$(FILES:.c=.o)

BONUS_OBJS	=	$(BONUS_FILES:.c=.o)

RM			=	rm -f

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address -g

PRINT_PATH	= ./ft_printf --no-print-directory
PRINT_NAME	= ./ft_printf/libftprintf.a

LIBFT_PATH	= ./libft --no-print-directory
LIBFT_NAME	= ./libft/libft.a

C_RED 		= \033[0;31m
GREEN 		= \033[1;92m
RESET 		= \033[0m
RED			= \033[38;5;160m
YELLOW		= \033[38;5;226m
INDI		= \033[38;5;99m
ORANGE		= \033[38;5;214m
GREY		= \033[38;5;250m
BLUE		= \033[38;5;87m
RESET		= \033[00m

all: $(PRINT_NAME) $(LIBFT_NAME) $(NAME)

$(PRINT_NAME):
	@echo "$(INDI) Compiling:$(RESET) ft_printf	\t\t$(GREEN) [OK]"
	@make -C $(PRINT_PATH) >/dev/null

$(LIBFT_NAME):
	@echo "$(INDI) Compiling:$(RESET) libft	\t\t$(GREEN) [OK]$(ORANGE)"
	@make -C $(LIBFT_PATH) >/dev/null

$(NAME):	$(OBJS)
			@echo "$(INDI) Compiling:$(RESET) pipex	\t\t$(GREEN) [OK]\n\n"
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_NAME) $(PRINT_NAME) >/dev/null
			@echo "$(BLUE)\t/ $(GREY)============================================== $(BLUE)\\ $(RESET)"
			@echo "$(BLUE)    <<<<<    [OK] $(YELLOW)    Pipex is ready to run!  $(BLUE) [OK]\t >>>>>"
			@echo "$(BLUE)\t\\ $(GREY)============================================== $(BLUE)/ $(RESET)\n\n"

$(NAME_BONUS):	$(BONUS_OBJS)
			@echo "$(INDI) Compiling:$(RESET) pipex_bonus	\t\t$(GREEN) [OK]\n\n"
			@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(BONUS_OBJS) $(LIBFT_NAME) $(PRINT_NAME) >/dev/null
			@echo "$(BLUE)\t/ $(GREY)============================================== $(BLUE)\\ $(RESET)"
			@echo "$(BLUE)    <<<<<    [OK] $(YELLOW) Pipex Bonus is ready to run!$(BLUE) [OK]\t >>>>>"
			@echo "$(BLUE)\t\\ $(GREY)============================================== $(BLUE)/ $(RESET)\n\n"

clean:
		@echo "\n$(GREY)----------\\ $(RESET)"
		@echo "$(RED)Cleaning$(GREY)...\\ $(RED)"
		@echo "$(GREY)------------\\ $(RESET)\n"
		@make fclean -C $(PRINT_PATH) >/dev/null
		@make fclean -C $(LIBFT_PATH) >/dev/null
		@$(RM) $(OBJS)
		@$(RM) $(BONUS_OBJS)

fclean:		clean
		@$(RM) $(NAME)
		@$(RM) $(NAME_BONUS)

re:		fclean all

bonus:	fclean $(PRINT_NAME) $(LIBFT_NAME) $(NAME_BONUS)