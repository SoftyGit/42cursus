NAME	= convert

CC		= c++
CFLAG	= -Wall -Wextra -Werror -std=c++98 #-g -fsanitize=address
CFLAG_TEMP = -Wall -Wextra -Werror -std=c++11 #-g -fsanitize=address
SRCS	= main.cpp
OBJS	= ${SRCS:.cpp=.o}

all		: ${NAME}

${NAME}	: ${OBJS}
	${CC} ${CFLAG_TEMP} -c ScalarConverter.cpp -o ScalarConverter.o
	${CC} ${CFLAG} -o ${NAME} ${OBJS} ScalarConverter.o

%.o		: %.cpp
	${CC} ${CFLAG} -c $< -o $@

clean	:
	rm -rf ${OBJS} ScalarConverter.o

fclean	: clean
	rm -rf ${NAME}

re		: fclean all