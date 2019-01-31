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
DPIN	=	$(DSRC)pin/
DSRC_UT	=	tests/src/

SRC		=	$(DSRC)Tristate.cpp					\
			$(DSRC)AComponent.cpp				\
			$(DPIN)PinInput.cpp					\
			$(DPIN)PinOutput.cpp				\
			$(DPIN)APin.cpp						\
			$(DCOMPONENT)ComponentAnd.cpp		\
			$(DCOMPONENT)ComponentInput.cpp		\
			$(DCOMPONENT)ComponentOutput.cpp	\

SRC_UT	=	$(wildcard $(DSRC_UT)*.cpp)			\

INC		=	-I$(DSRC) -I$(DCOMPONENT) -I$(DPIN)
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

tests_clean:
	rm -f $(NAME_UT) *.gcno *.gcov *.gcda

.PHONY: all clean fclean re debug tests_run tests_debug
