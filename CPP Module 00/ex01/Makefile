NAME	= PhoneBook

CC		= c++
CFLAG	= -Wall -Wextra -Werror -std=c++98
SRCS	= Contact.cpp PhoneBook.cpp main.cpp
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