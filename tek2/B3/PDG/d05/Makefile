##
## EPITECH PROJECT, 2020
## makefile
## File description:
## desc
##

SRC		=	$(shell find ./ -name "*.c")

SRC_T 		=	init_and_destroy.c \
				assign.c \
				append.c \
				at.c \
				clear.c \
				length.c \
				compare.c \
				copy.c \
				contain.c \
				empty.c \
				find.c \
				insert.c \
				to_int.c \

TEST_FILES 	=	$(shell find ./tests -name "*.c") \

NAME	=	libstring.a

TEST_N		=	unit_tests

OBJ			=	$(SRC:.c=.o)

OBJTEST		=	$(SRC_T:.c=.o)

CC		= 	gcc

CFLAGS	=	-std=gnu17 -Wall -Wextra

T_FLAGS		=	-lcriterion --coverage

RM		=	rm -rf

AR      =   ar

all:	$(NAME)

$(NAME):	$(OBJ)
	$(AR) rc $(NAME) $(OBJ)

tests_run:
			$(CC) -o $(TEST_N) $(TEST_FILES) $(SRC_T) $(T_FLAGS)
			./unit_tests --verbose
			gcovr --exclude-throw-branches --exclude-unreachable-branches \
			-e tests/ -e main.c -b

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) $(TEST_N)
	$(RM) vgcore.*

re: fclean all

.PHONY = re fclean clean tests_run $(NAME)
