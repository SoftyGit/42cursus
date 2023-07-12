NAME = push_swap
BONUS = checker
CC = CC
CFLAG = -Wall -Wextra -Werror -fsanitize=address

SRCS =		srcs/main.c\
			srcs/lib.c\
			srcs/err.c\
			srcs/order1.c\
			srcs/order2.c\
			srcs/order3.c\
			srcs/sort1.c\
			srcs/sort2.c

BNSRCS =	bonus/main_bonus.c\
			bonus/lib_bonus.c\
			bonus/err_bonus.c\
			bonus/order1_bonus.c\
			bonus/order2_bonus.c\
			bonus/order3_bonus.c\
			bonus/sort_bonus.c\
			bonus/input_bonus.c

GNL =		gnl/get_next_line_bonus.c\
			gnl/get_next_line_utils_bonus.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

bonus: ${BONUS}

${BONUS}:
	${CC} ${CFLAG} ${BNSRCS} ${GNL} -o ${BONUS}

${NAME}:
	${CC} ${CFLAG} ${SRCS} -o ${NAME}

clean:

fclean: clean
	rm -rf ${NAME}
	rm -rf ${BONUS}

re: fclean all

.PHONY: bonus clean fclean re