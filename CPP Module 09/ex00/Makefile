NAME	= btc

CC		= c++
CFLAG	= -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
SRCS	= main.cpp BitcoinExchange.cpp
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