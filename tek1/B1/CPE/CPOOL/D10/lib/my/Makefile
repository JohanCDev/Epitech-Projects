##
## EPITECH PROJECT, 2020
## makefile
## File description:
## desc
##

SRC	=	$(shell find -type f -name "*.c")

NAME	=	libmy.a

OBJ	= 	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	mkdir ../../include/
	cp my.h ../../include/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all
