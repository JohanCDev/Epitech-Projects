##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

DIR		=		src/

SRC     =       $(DIR)main.cpp \

OBJ     =       $(SRC:.cpp=.o)

CC		=		g++

NAME    =       my_cat

CFLAGS  =       -std=c++20 -Wall -Wextra -Werror

all:            $(NAME)

$(NAME):        $(OBJ)
				$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
				rm -f $(OBJ)

fclean:         clean
				rm -f $(NAME)

re:             fclean all
