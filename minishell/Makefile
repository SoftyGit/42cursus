NAME = minishell

CC = CC
CFLAG = -Wall -Wextra -Werror
LDFLAG = -lreadline -L/usr/local/lib
CMFLAG = -I/opt/homebrew/opt/readline/include
SRCS =	src/main.c src/prompt.c\
		src/signals.c\
		src/envp/envp.c src/envp/envp2.c\
		src/parse/parse1.c src/parse/parse2.c src/parse/parse3.c src/parse/parse4.c\
		src/utils/utils1.c src/utils/utils2.c src/utils/utils3.c src/utils/utils4.c src/utils/utils5.c \
		src/utils/utils6.c src/utils/utils7.c src/utils/utils8.c src/utils/utils9.c src/utils/utils10.c src/utils/utils11.c src/utils/draw_logo.c\
		src/execute1.c\
		src/redirection1.c\
		src/pipex/input.c src/pipex/pipex.c src/pipex/pipex_bonus.c src/pipex/utils.c src/pipex/utils_2.c\
		src/GNL/get_next_line.c src/GNL/get_next_line_utils.c\
		src/builtin/env.c src/builtin/echo.c src/builtin/pwd.c src/builtin/unset.c src/builtin/cd.c src/builtin/cd2.c src/builtin/export.c src/builtin/exit.c
OBJS = ${SRCS:.c=.o}
DEBUG = debug
DEBUG_FOLDER = minishell.dSYM

all		: ${NAME}

${NAME}	: ${OBJS}
	${CC} ${CFLAG} ${LDFLAG} -o ${NAME} ${OBJS}

${DEBUG} :
	gcc ${CFLAG} -I./header -I./gnl ${CMFLAG} ${LDFLAG} ${SRCS} -o ${NAME} -g

%.o		: %.c
	${CC} ${CFLAG} ${CMFLAG} -I./header -c $< -o $@

clean	:
	rm -rf ${OBJS}
	rm -rf ${DEBUG_FOLDER}

fclean	: clean
	rm -rf ${NAME}

re		: fclean all

.PHONY: bonus clean
