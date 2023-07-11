NAME = push_swap
CC = CC
CFLAG = -Wall -Wextra -Werror

SRCS =	srcs/main.c\
		srcs/lib.c\
		srcs/err.c\
		srcs/order1.c\
		srcs/order2.c\
		srcs/order3.c\
		srcs/sort1.c\
		srcs/sort2.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

bonus : 

${NAME}:
	${CC} ${CFLAG} ${SRCS} -o ${NAME}

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@ -I.

clean:

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: bonus clean fclean re