NAME1 = client
NAME2 = server
PRINTF = ft_printf
LIBFT = libft
LIBFT_LIB = libft.a
CC = CC
CFLAG = -Wall -Wextra -Werror

SRCS =	ft_printf/ft_format1.c\
		ft_printf/ft_format2.c\
		ft_printf/ft_helper.c\
		ft_printf/ft_printf.c

SRCS1 =	client.c
SRCS2 = server.c

OBJS1 = ${SRCS1:.c=.o}
OBJS2 = ${SRCS2:.c=.o}


all: ${NAME1} ${NAME2}

bonus : 

${NAME1}:
	make all -C ${PRINTF}/${LIBFT}
	${CC} ${SRCS} ${SRCS1} -L./${PRINTF}/${LIBFT} -lft -o ${NAME1}

${NAME2}:
	${CC} ${SRCS} ${SRCS2} -L./${PRINTF}/${LIBFT} -lft -o ${NAME2}

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@ -I.

clean:
	make clean -C ${PRINTF}/${LIBFT}

fclean: clean
	make fclean -C ${PRINTF}/${LIBFT}
	rm -rf ${NAME1}
	rm -rf ${NAME2}

re: fclean all

.PHONY: bonus clean fclean re