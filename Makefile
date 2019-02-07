##
## EPITECH PROJECT, 2018
## cpp_d01_2018
## File description:
## Makefile
##

CC		=	g++

DTESTS	=	tests/
DSRC	=	src/
DCOMPONENT	=	$(DSRC)component/
DCOMPONENTS	=	$(DCOMPONENT)basic_components/
DPARSER	=	$(DSRC)parser/
DPIN	=	$(DSRC)pin/
DSRC_UT	=	$(DTESTS)src/
DGTEST	=	gtest/

SRC		=	$(DPIN)Tristate.cpp					\
			$(DPIN)PinInput.cpp					\
			$(DPIN)PinOutput.cpp				\
			$(DPIN)APin.cpp						\
			$(DPIN)PinException.cpp				\
			$(DCOMPONENT)ComponentFactory.cpp	\
			$(DCOMPONENT)AComponent.cpp			\
			$(DCOMPONENT)Exec.cpp				\
			$(DCOMPONENTS)ComponentInput.cpp	\
			$(DCOMPONENTS)ComponentOutput.cpp	\
			$(DCOMPONENTS)ComponentTrue.cpp		\
			$(DCOMPONENTS)ComponentFalse.cpp	\
			$(DCOMPONENTS)ComponentNot.cpp		\
			$(DCOMPONENTS)ComponentAnd.cpp		\
			$(DCOMPONENTS)ComponentOr.cpp		\
			$(DCOMPONENTS)ComponentXor.cpp		\
			$(DCOMPONENTS)ComponentNand.cpp		\
			$(DCOMPONENTS)ComponentNor.cpp		\
			$(DPARSER)ArgParser.cpp				\
			$(DPARSER)FileParser.cpp			\
			$(DPARSER)Parser.cpp				\
			$(DPARSER)ParserException.cpp		\
			$(DPARSER)KeyValue.cpp				\
			$(DPARSER)Shell.cpp					\

SRC_UT	=	$(wildcard $(DSRC_UT)*.cpp)							\
			$(wildcard $(DSRC_UT)pin/*.cpp)						\
			$(wildcard $(DSRC_UT)parser/*.cpp)					\
			$(wildcard $(DSRC_UT)components/*.cpp)				\

INC		=	-I$(DSRC) -I$(DCOMPONENT) -I$(DPIN) -I$(DPARSER) -I$(DCOMPONENTS) -I.
CXXFLAGS	+=  -Wall -Wextra $(INC) -DPROJECT_PATH=""
LDFLAGS	=	-lgtest -lgtest_main
OBJ		=	$(SRC:.cpp=.o)

NAME	=	nanotekspice
NAME_UT	=	units

all: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) main.cpp $(CXXFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_UT)

re: fclean all

debug: CXXFLAGS += -g
debug: re

tests_run: CXXFLAGS += --coverage -ftest-coverage -fprofile-arcs -lgcov
tests_run:
	$(CC) -o $(NAME_UT) $(SRC) $(SRC_UT) $(CXXFLAGS) $(LDFLAGS)
	./$(NAME_UT)
	gcov *.gcno &> /dev/null

tests_debug: CXXFLAGS += -g
tests_debug: tests_run

tests_clean:
	rm -f $(NAME_UT) *.gcno *.gcov *.gcda

.PHONY: all clean fclean re debug tests_run tests_debug tests_clean
