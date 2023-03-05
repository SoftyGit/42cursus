NAME = so_long
CC = CC
CFLAG = -Wall -Wextra -Werror -fsanitize=address
MLXFLAG = -I./mlx -L./mlx -lmlx -framework OpenGL -framework AppKit
PATH_MLX = ./mlx


SRCS =  gnl/get_next_line.c\
		gnl/get_next_line_utils.c\
		srcs/sl_init.c\
		srcs/sl_input_hooks.c\
		srcs/sl_main.c\
		srcs/sl_map_utils.c\
		srcs/sl_other_utils.c\
		srcs/sl_output.c\
		srcs/sl_path_utils.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

bonus : 

${NAME}: ${OBJS}
	${CC} ${CFLAG} ${MLXFLAG} ${OBJS} -o ${NAME}

%.o: %.c
	${CC} ${CFLAG} -c $< -o $@

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all


.PHONY: bonus clean fclean re