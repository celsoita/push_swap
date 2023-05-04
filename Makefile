CC = gcc

NAME = push_swap

NAME_B = checker

SRC = ft_check_error.c ft_op.c ft_stacks.c ft_algorithm.c ft_mvorder.c ft_free.c ft_check_stack.c main.c ft_oprotate.c ft_order.c ft_calculatemv.c ft_search_content.c

SRC_B = push_swap_bonus/main_bonus.c push_swap_bonus/ft_init_bonus.c \
		push_swap_bonus/ft_stacks_bonus.c push_swap_bonus/ft_free_bonus.c \
		push_swap_bonus/ft_check_error_bonus.c push_swap_bonus/ft_check_op_bonus.c \
		push_swap_bonus/ft_oprotate_bonus.c push_swap_bonus/ft_op_bonus.c

CFLAG = -Wall -Wextra -Werror -g

LIBFT = libft/libft.a

all : $(NAME)

$(NAME): libcomp comp 

libcomp:
		@make -C libft

comp : 
	gcc $(CFLAG) $(SRC) $(LIBFT) -o $(NAME)

bonus : libcomp
	gcc $(CFLAG) $(SRC_B) $(LIBFT) -o $(NAME_B)

%.o:%.c
	@$(CC) -c $(CFLAG) -I. $< -o $@

status:
	echo "\033[5;1;92mcompleted\033[0m"

libclean:
		@make clean -C libft
		
clean: status libclean
	/bin/rm -f *.o
	/bin/rm -f libft/*.o
	/bin/rm -f push_swap_bonus/*.o

libfclean:
		@make fclean -C libft

fclean: clean libfclean
	/bin/rm -f $(NAME)
	/bin/rm -f $(NAME_B)

re: fclean all

.PHONY: all clean fclean re bonus
.SILENT: