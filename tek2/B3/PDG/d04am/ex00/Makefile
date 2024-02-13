##
## EPITECH PROJECT, 2021
## Duo-7
## File description:
## Makefile
##

SRC			=	z.c

NAME		=	z

OBJ			=	$(SRC:.c=.o)

CFLAGS		=	-std=gnu17 -Wall -Wextra

CC			=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
			@find -type f -name '*.o' -delete
			@find -type f -name 'vgcore.*' -delete

fclean:		clean
			rm -f $(NAME)

re:			fclean all

debug: 		CFLAGS += -g
debug: 		re

.PHONY: 	all clean fclean re debug
