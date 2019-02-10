/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** testsParser.cpp
*/

#include "gtest/gtest.h"
#include "Parser.hpp"
#include "IComponent.hpp"

void testParser(int ac, const char *av[], nts::Tristate expected)
{
	nts::Parser parser(ac, av);
	const std::vector<std::unique_ptr<nts::IComponent>> &components = parser.getComponents();

	components[2]->compute(0);
	EXPECT_EQ(components[2]->getPin(0)->getState(), expected);
}

TEST(Parser, AndCompute)
{
	const char *av0[] = {"bin", PROJECT_PATH"samples/gates/and.nts", "a=0", "b=0"};
	const char *av1[] = {"bin", PROJECT_PATH"samples/gates/and.nts", "a=1", "b=0"};
	const char *av2[] = {"bin", PROJECT_PATH"samples/gates/and.nts", "a=0", "b=1"};
	const char *av3[] = {"bin", PROJECT_PATH"samples/gates/and.nts", "a=1", "b=1"};
	const char *av4[] = {"bin", PROJECT_PATH"samples/gates/and.nts"};

	testParser(4, av0, nts::Tristate::FALSE);
	testParser(4, av1, nts::Tristate::FALSE);
	testParser(4, av2, nts::Tristate::FALSE);
	testParser(4, av3, nts::Tristate::TRUE);
	testParser(2, av4, nts::Tristate::UNDEFINED);
}
