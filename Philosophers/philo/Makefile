NAME = philo

CC = CC
CFLAG = -Wall -Wextra -Werror
SRCS =	main.c\
		cycle.c\
		errno.c\
		utils.c
OBJS = ${SRCS:.c=.o}

all		: ${NAME}

${NAME}	: ${OBJS}
	${CC} ${CFLAG} -o ${NAME} ${OBJS}

%.o		: %.c
	${CC} ${CFLAG} -c $< -o $@

clean	:
	rm -rf ${OBJS}

fclean	: clean
	rm -rf ${NAME}

re		: fclean all

.PHONY: bonus clean