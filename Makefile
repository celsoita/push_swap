CC = gcc

NAME = push_swap

SRC = ft_add.c ft_check_error.c ft_op.c

CFLAG = -Wall -Wextra -Werror -g

LIBFT = libft/libft.a 

all : $(NAME)

$(NAME): libcomp comp 

libcomp:
		@make -C libft

comp : 
	gcc $(CFLAG) $(SRC) $(LIBFT) -o $(NAME)

%.o:%.c
	@$(CC) -c $(CFLAG) -I. $< -o $@

status:
	echo "\033[5;1;92mcompleted\033[0m"

libclean:
		@make clean -C libft
		
clean: status libclean
	/bin/rm -f *.o
	/bin/rm -f libft/*.o

libfclean:
		@make fclean -C libft

fclean: clean libfclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT: