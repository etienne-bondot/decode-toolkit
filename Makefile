
DEBUG	= yes

NAME	= decode

SRC	= src/main.c		\
	  src/cesar.c		\
	  src/error.c		\
	  src/globales.c	\
	  src/parse_options.c	\
	  src/utils_1.c

IFLAG	= -Iinclude

LFLAG	=

ifeq ($(DEBUG), yes)
	CC	= cc -g
else
	CC	= cc
endif

RM	= rm -rf

CFLAGS	= $(LFLAG) $(IFLAG) -Wall -Wextra -pedantic -ansi

OBJ_DIR = obj

OBJ	= $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME):$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(OBJ_DIR)/%.o: %.c
	@mkdir -p `dirname $@`
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: all clean fclean re

