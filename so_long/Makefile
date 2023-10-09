NAME = so_long
BNNAME = so_long_bonus
CC = CC
CFLAG = -Wall -Wextra -Werror
MLXFLAG = -I./mlx -L./mlx -lmlx -framework OpenGL -framework AppKit


SRCS =  gnl/get_next_line.c\
		gnl/get_next_line_utils.c\
		srcs/sl_init.c\
		srcs/sl_input_hooks.c\
		srcs/sl_main.c\
		srcs/sl_map_utils.c\
		srcs/sl_other_utils.c\
		srcs/sl_output.c\
		srcs/sl_path_utils.c

SRBN = 	gnl/get_next_line_bonus.c\
		gnl/get_next_line_utils_bonus.c\
		srcs_bns/sl_init_bonus.c\
		srcs_bns/sl_input_hooks_bonus.c\
		srcs_bns/sl_main_bonus.c\
		srcs_bns/sl_map_utils_bonus.c\
		srcs_bns/sl_other_utils_bonus.c\
		srcs_bns/sl_output_bonus.c\
		srcs_bns/sl_path_utils_bonus.c\
		srcs_bns/sl_sprite_bonus.c

OBJS = ${SRCS:.c=.o}
OBBN = ${SRBN:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAG} ${MLXFLAG} ${OBJS} -o ${NAME}

bonus: ${BNNAME}

${BNNAME}: ${OBBN}
	${CC} ${CFLAG} ${MLXFLAG} ${OBBN} -o ${BNNAME}

%.o: %.c
	${CC} ${CFLAG} -c $< -o $@

clean:
	rm -rf ${OBJS}
	rm -rf ${OBBN}

fclean: clean
	rm -rf ${NAME}
	rm -rf ${BNNAME}

re: fclean all

.PHONY: bonus clean fclean re