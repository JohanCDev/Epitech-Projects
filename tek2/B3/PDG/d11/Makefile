##
## EPITECH PROJECT, 2020
## makefile
## File description:
## desc
##

SRC_T 		=	$(shell find ./ex05 -name "*.cpp") \

TEST_FILES 	=	$(shell find ./tests -name "*.cpp") \

TEST_N		=	unit_tests

OBJTEST		=	$(SRC_T:.cpp=.o)
OBJTESTF	=	$(TEST_FILES:.cpp=.o)

CC		= 	g++

CXXFLAGS	=	-Wall -Wextra -std=c++17 --coverage

T_FLAGS		=	 -lcriterion --coverage

RM		=	rm -rf

AR      =   ar

tests_run:	$(OBJTEST) $(OBJTESTF)
			$(CC) -o $(TEST_N) $(OBJTESTF) $(OBJTEST) $(T_FLAGS)
			./unit_tests --verbose
			gcov $(SRC_T)
			gcovr -g -k -r .

clean:
	$(RM) $(OBJTESTF)
	$(RM) $(OBJTEST)

fclean:		clean
	$(RM) $(NAME)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.gcov
	$(RM) **/*.gcda
	$(RM) **/*.gcno
	$(RM) **/*.gcov
	$(RM) $(TEST_N)
	$(RM) vgcore.*

.PHONY = fclean clean tests_run
