##
## EPITECH PROJECT, 2020
## makefile
## File description:
## desc
##

SRC_T 		=	Peasant.cpp \
				Knight.cpp \
				Enchanter.cpp \
				Priest.cpp \
				Paladin.cpp \

TEST_FILES 	=	$(shell find ./tests -name "*.cpp") \

TEST_N		=	unit_tests

OBJTEST		=	$(SRC_T:.cpp=.o)

CC		= 	g++

CPPFLAGS	=	-Wall -Wextra

T_FLAGS		=	 -lcriterion --coverage

RM		=	rm -rf

AR      =   ar

tests_run:
			$(CC) -o $(TEST_N) $(TEST_FILES) $(SRC_T) $(T_FLAGS)
			./unit_tests --verbose
			gcovr --exclude-throw-branches --exclude-unreachable-branches \
			-e tests/ -e main.cpp -b

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) $(TEST_N)
	$(RM) vgcore.*

.PHONY = fclean clean tests_run
