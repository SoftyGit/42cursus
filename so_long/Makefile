NAME = libftprintf.a
CC = CC
CFLAG = -Wall -Wextra -Werror
MLX_PATH = ./mlx


SRCS =  main.c

OBJS = ${SRCS:.c=.o}

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