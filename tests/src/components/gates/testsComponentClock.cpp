/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** testsComponentClock.cpp
*/

#include "gtest/gtest.h"
#include "Tristate.hpp"
#include "ComponentClock.hpp"
#include "Parser.hpp"
#include "Exec.hpp"

TEST(ComponentClock, Init)
{
	nts::ComponentClock clock("clock");

	EXPECT_EQ(clock.getPin(0)->getState(), nts::UNDEFINED);
	clock.getPin(0)->setState(nts::FALSE);
	EXPECT_EQ(clock.getPin(0)->getState(), nts::FALSE);
}

TEST(ComponentClock, LocalCompute)
{
	nts::ComponentClock clock("clock");

	clock.getPin(0)->setState(nts::FALSE);
	clock.compute(0);
	EXPECT_EQ(clock.getPin(0)->getState(), nts::FALSE);
}

TEST(ComponentClock, ExecCompute)
{
	static const char *av[] = {"bin", PROJECT_PATH"samples/basic_components/clock.nts", "c=1"};
	nts::Parser parser(3, av);

	EXPECT_EQ(parser.getComponents()[0]->getPin(0)->getState(), nts::TRUE);
	EXPECT_TRUE(parser.getComponents()[0]->getName() == "c");
	EXPECT_TRUE(parser.getComponents()[1]->getType() == "output");
	EXPECT_EQ(nts::ComponentClock::upDown, nts::ComponentClock::DOWN);
	nts::Exec::compute(parser.getComponents());
	EXPECT_EQ(nts::ComponentClock::upDown, nts::ComponentClock::UP);
	EXPECT_EQ(parser.getComponents()[1]->getPin(0)->getState(), nts::TRUE);
	nts::Exec::compute(parser.getComponents());
	EXPECT_EQ(parser.getComponents()[1]->getPin(0)->getState(), nts::FALSE);
}
