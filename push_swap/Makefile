NAME = push_swap
CC = CC
CFLAG = -Wall -Wextra -Werror -fsanitize=address

SRCS =	main.c\
		lib.c\
		err.c\
		order1.c\
		order2.c\
		order3.c\
		sort.c\
		test.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

bonus : 

${NAME}:
	${CC} ${SRCS} -o ${NAME}

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@ -I.

clean:

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: bonus clean fclean re