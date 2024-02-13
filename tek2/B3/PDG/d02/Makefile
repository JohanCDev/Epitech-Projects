##
## EPITECH PROJECT, 2022
## COMMUNISTE
## File description:
## Makefile
##

NAME	=	doop

SRC		=	DoOp.hs

FLAG	=	-Wall -W

RM		=	rm -f

CC		=	ghc

all:		$(NAME)

$(NAME):
		$(CC) -o $(NAME) $(SRC)

clean:
		@$(RM) *.o
		@$(RM) *.hi

fclean:	clean
		@$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re name 
