NAME1 = client
NAME2 = server
BNNAME1 = client_bonus
BNNAME2 = server_bonus

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
BNSRCS1 = bns/client_bonus.c
BNSRCS2 = bns/server_bonus.c

OBJS1 = ${SRCS1:.c=.o}
OBJS2 = ${SRCS2:.c=.o}
BNOBJS1 = ${BNSRCS1:.c=.o}
BNOBJS2 = ${BNSRCS2:.c=.o}

all: ${NAME1} ${NAME2}

bonus : ${BNNAME1} ${BNNAME2}

${NAME1}: ${OBJS1}
	make all -C ${PRINTF}/${LIBFT}
	${CC} ${CFLAG} ${SRCS} ${SRCS1} -L./${PRINTF}/${LIBFT} -lft -o ${NAME1}

${NAME2}: ${OBJS2}
	${CC} ${CFLAG} ${SRCS} ${SRCS2} -L./${PRINTF}/${LIBFT} -lft -o ${NAME2}

${BNNAME1}: ${BNOBJS1}
	make all -C ${PRINTF}/${LIBFT}
	${CC} ${CFLAG} ${SRCS} ${BNSRCS1} -L./${PRINTF}/${LIBFT} -lft -o ${BNNAME1}

${BNNAME2}: ${BNOBJS2}
	${CC} ${CFLAG} ${SRCS} ${BNSRCS2} -L./${PRINTF}/${LIBFT} -lft -o ${BNNAME2}

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@ -I.

clean:
	make clean -C ${PRINTF}/${LIBFT}
	rm -rf ${OBJS1}
	rm -rf ${OBJS2}
	rm -rf ${BNOBJS1}
	rm -rf ${BNOBJS2}

fclean: clean
	make fclean -C ${PRINTF}/${LIBFT}
	rm -rf ${NAME1}
	rm -rf ${NAME2}
	rm -rf ${BNNAME1}
	rm -rf ${BNNAME2}

re: fclean all

.PHONY: bonus clean fclean re