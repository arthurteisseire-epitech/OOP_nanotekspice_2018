##
## EPITECH PROJECT, 2018
## cpp_d01_2018
## File description:
## Makefile
##

CC		=	g++
DTESTS	=	tests/
DSRC	=	src/
DCOMPONENT	=	$(DSRC)components/
DSRC_UT	=	tests/src/

SRC		=	$(DSRC)Tristate.cpp				\
			$(DSRC)AComponent.cpp			\
			$(DCOMPONENT)ComponentAnd.cpp	\

SRC_UT	=	$(DSRC_UT)testsTristate.cpp			\

INC		=	-I$(DSRC) -I$(DCOMPONENT)
CXXFLAGS	+=  -Wall -Wextra $(INC)
LDFLAGS	=	-lcriterion
OBJ		=	$(SRC:.cpp=.o)
NAME	=	nanotekspice
NAME_UT	=	units

all: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_UT)

re: fclean all

debug: CXXFLAGS += -g
debug: re

tests_run: CXXFLAGS += --coverage
tests_run:
	$(CC) -o $(NAME_UT) $(SRC) $(SRC_UT) $(CXXFLAGS) $(LDFLAGS)
	./$(NAME_UT)
	gcov *.gcno &> /dev/null

tests_debug: CXXFLAGS += -g
tests_debug: tests_run

.PHONY: all clean fclean re debug tests_run tests_debug
