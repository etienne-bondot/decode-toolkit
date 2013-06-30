##
## Makefile for decode-tools in /home/bondot_e/Epitech/2017/projets_perso/decode-toolkit
## 
## Made by bondot_e
## Login   <bondot_e@epitech.net>
## 
## Started on  Sun Jun 30 09:48:48 2013 bondot_e
## Last update Sun Jun 30 12:09:44 2013 bondot_e
##

DEBUG	= yes

NAME	= decode-tools

SRC	= src/main.c		\
	  src/cesar.c		\
	  src/vigenere.c	\
	  src/text_analysis.c	\
	  src/error.c		\
	  src/globales.c	\
	  src/parse_options.c	\
	  src/str_to_wordtab.c	\
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

