NAME = so_long
CC = CC
CFLAG = -Wall -Wextra -Werror
PATH_MLX = ./mlx


SRCS =  gnl/get_next_line.c\
		gnl/get_next_line_utils.c\
		srcs/sl_init.c\
		srcs/sl_input_hooks.c\
		srcs/sl_main.c\
		srcs/sl_map_utils.c\
		srcs/sl_other_utils.c\
		srcs/sl_output.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

bonus : 

${NAME}: 
	$(CC) $(CFLAG) ${SRCS} -o ${NAME} -I.

clean:
	make clean -C ${LIBFT}
	rm -rf ${OBJS}

fclean: clean
	make fclean -C ${LIBFT}
	rm -rf ${NAME}

re: fclean all

.PHONY: bonus clean fclean re