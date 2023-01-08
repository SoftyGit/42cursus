NAME = libftprintf.a
LIBFT = libft
LIBFT_LIB = libft.a
CC = CC
CFLAG = -Wall -Wextra -Werror

SRCS =  ft_format1.c\
		ft_format2.c\
		ft_helper.c\
		ft_printf.c\

OBJS = ${SRCS:.c=.o}

BNSRCS =

BNOBJS = ${BNSRCS:.c=.o}

all: ${NAME}

bonus : 

${NAME}: $(OBJS)
	make all -C ${LIBFT}
	cp ${LIBFT}/${LIBFT_LIB} ${NAME}
	ar rc $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@ -I.

clean:
	make clean -C ${LIBFT}
	rm -rf ${OBJS}

fclean: clean
	make fclean -C ${LIBFT}
	rm -rf ${NAME}

re: fclean all

.PHONY: bonus clean fclean re