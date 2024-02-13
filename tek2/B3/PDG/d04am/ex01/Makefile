##
## EPITECH PROJECT, 2021
## Duo-7
## File description:
## Makefile
##

SRC			=	mul_div.c

SRC_T 		=	mul_div.c

TEST_FILES 	=	$(shell find ./tests -name "*.c") \

NAME		=	mul_div

TEST_N		=	unit_tests

OBJ			=	$(SRC:.c=.o)

OBJTEST		=	$(SRC_T:.c=.o)

CFLAGS		=	-std=gnu17 -Wall -Wextra

T_FLAGS		=	-lcriterion --coverage

CC			=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

tests_run:
			$(CC) -o $(TEST_N) $(TEST_FILES) $(SRC_T) $(T_FLAGS)
			./unit_tests --verbose
			gcovr --exclude-throw-branches --exclude-unreachable-branches \
			-e lib/tests/ -e tests/ -e $(SRC_DIR)main.c -b

clean:
			@find -type f -name '*.o' -delete
			@find -type f -name '*.gcda' -delete
			@find -type f -name '*.gcno' -delete
			@find -type f -name 'vgcore.*' -delete

fclean:		clean
			rm -f $(NAME)
			rm -f $(TEST_N)

re:			fclean all

debug: 		CFLAGS += -g
debug: 		re

.PHONY: 	all clean fclean re tests_run debug
