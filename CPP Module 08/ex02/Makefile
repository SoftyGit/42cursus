NAME	= ex02

CC		= c++
CFLAG	= -Wall -Wextra -Werror -g -fsanitize=address #-std=c++98
SRCS	= main.cpp
OBJS	= ${SRCS:.cpp=.o}

all		: ${NAME}

${NAME}	: ${OBJS}
	${CC} ${CFLAG} -o ${NAME} ${OBJS}

%.o		: %.cpp
	${CC} ${CFLAG} -c $< -o $@

clean	:
	rm -rf ${OBJS}

fclean	: clean
	rm -rf ${NAME}

re		: fclean all