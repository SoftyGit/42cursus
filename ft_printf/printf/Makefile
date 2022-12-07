NAME = libftprintf.a

CC = gcc
CFLAG = -Wall -Wextra -Werror

SRCS =  ft_memchr.c

OBJS = ${SRCS:.c=.o}

BNSRCS =ft_lstnew.c

BNOBJS = ${BNSRCS:.c=.o}

all: ${NAME}

bonus : ${BNOBJS}
	ar rc $(NAME) $(BNOBJS)

${NAME}: $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: bonus clean fclean re