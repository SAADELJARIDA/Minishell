SRC = main.c free_all.c lexer.c save_garbage.c

NAME = minishell
HEADER = minishell.h
OBJ = ${SRC:.c=.o}

CC = cc

CFLAGS = -Wall -Wall -Werror 

LIB_DIR = libft
LIB_FILE = libft.a
LIB = $(LIB_DIR)/$(LIB_FILE)

RM = rm -f

all: ${NAME}

${NAME}: ${OBJ} ${HEADER} ${LIB}
	${CC} ${OBJ} ${LIB} -lreadline -o ${NAME}

$(LIB):
	$(MAKE) -C $(LIB_DIR)

clean:
	${RM} ${OBJ}
	$(MAKE) clean -C $(LIB_DIR)
fclean:
	${RM} ${NAME} ${OBJ}
	$(MAKE) fclean -C $(LIB_DIR)
re: fclean all