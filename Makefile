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
DCIRCUIT	=	$(DCOMPONENT)circuits/
DGATES	=	$(DCOMPONENT)gates/
DPARSER	=	$(DSRC)parser/
DPIN	=	$(DSRC)pin/
DGTEST	=	gtest/

DSRC_UT		=	$(DTESTS)src/
DUT_COMP	=	$(DSRC_UT)components/
DUT_CIRC	=	$(DUT_COMP)circuits/
DUT_GAT		=	$(DUT_COMP)gates/

SRC		=	$(DPIN)Tristate.cpp					\
			$(DPIN)PinInput.cpp					\
			$(DPIN)PinOutput.cpp				\
			$(DPIN)APin.cpp						\
			$(DPIN)PinException.cpp				\
			$(DCOMPONENT)ComponentFactory.cpp	\
			$(DCOMPONENT)AComponent.cpp			\
			$(DCOMPONENT)ACircuit.cpp			\
			$(DCOMPONENT)Exec.cpp				\
			$(DCOMPONENT)ComponentException.cpp	\
			$(DGATES)ComponentInput.cpp			\
			$(DGATES)ComponentOutput.cpp		\
			$(DGATES)ComponentTrue.cpp			\
			$(DGATES)ComponentFalse.cpp			\
			$(DGATES)ComponentClock.cpp			\
			$(DGATES)ComponentNot.cpp			\
			$(DGATES)ComponentAnd.cpp			\
			$(DGATES)ComponentXAnd.cpp			\
			$(DGATES)ComponentOr.cpp			\
			$(DGATES)ComponentXor.cpp			\
			$(DGATES)ComponentXOr.cpp			\
			$(DGATES)ComponentNand.cpp			\
			$(DGATES)ComponentNor.cpp			\
			$(DGATES)ComponentSplit.cpp			\
			$(DGATES)ComponentFlipFlop.cpp		\
			$(DCIRCUIT)ComponentHalfAdder.cpp	\
			$(DCIRCUIT)ComponentAdder.cpp		\
			$(DCIRCUIT)ComponentNGates.cpp		\
			$(DCIRCUIT)Component4001.cpp		\
			$(DCIRCUIT)Component4008.cpp		\
			$(DCIRCUIT)Component4011.cpp		\
			$(DCIRCUIT)Component4013.cpp		\
			$(DCIRCUIT)Component4030.cpp		\
			$(DCIRCUIT)Component4069.cpp		\
			$(DCIRCUIT)Component4071.cpp		\
			$(DCIRCUIT)Component4081.cpp		\
			$(DCIRCUIT)Component4503.cpp		\
			$(DPARSER)ArgParser.cpp				\
			$(DPARSER)FileParser.cpp			\
			$(DPARSER)Parser.cpp				\
			$(DPARSER)ParserException.cpp		\
			$(DPARSER)KeyValue.cpp				\
			$(DPARSER)Shell.cpp					\

MAIN =	main.cpp

SRC_UT	=	$(wildcard $(DSRC_UT)*.cpp)				\
			$(wildcard $(DSRC_UT)pin/*.cpp)			\
			$(wildcard $(DSRC_UT)parser/*.cpp)		\
			$(wildcard $(DUT_COMP)*.cpp)			\
			$(wildcard $(DUT_GAT)*.cpp)				\
			$(wildcard $(DUT_CIRC)*.cpp)			\

INC		=	-I$(DSRC) -I$(DCOMPONENT) -I$(DCIRCUIT) -I$(DPIN) -I$(DPARSER) -I$(DGATES) -I.
INC_UT	=	-I$(DSRC_UT)

CXXFLAGS	+=  -Wall -Wextra $(INC) -DPROJECT_PATH=""
LDFLAGS	=	-lgtest -lgtest_main
OBJ		=	$(SRC:.cpp=.o) $(MAIN:.cpp=.o)

NAME	=	nanotekspice
NAME_UT	=	units

all: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS)

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
	$(CC) -o $(NAME_UT) $(SRC) $(SRC_UT) $(CXXFLAGS) $(LDFLAGS) $(INC_UT)
	./$(NAME_UT)
	gcov *.gcno &> /dev/null

tests_debug: CXXFLAGS += -g
tests_debug: tests_run

tests_clean:
	rm -f $(NAME_UT) *.gcno *.gcov *.gcda

.PHONY: all clean fclean re debug tests_run tests_debug tests_clean
