/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** testsComponent4030.cpp
*/

#include "gtest/gtest.h"
#include "Parser.hpp"
#include "Exec.hpp"
#include "FileParser.hpp"
#include "ComponentInput.hpp"
#include "ComponentOutput.hpp"
#include "ComponentAnd.hpp"
#include "Component4030.hpp"

TEST(Component4030, Init)
{
	nts::Component4030 component4030("4030");

	EXPECT_EQ(component4030.getPin(0), component4030.getComponents()[0]->getPin(0));
	EXPECT_EQ(component4030.getPin(1), component4030.getComponents()[0]->getPin(1));
	EXPECT_EQ(component4030.getPin(2), component4030.getComponents()[0]->getPin(2));
}

TEST(Component4030, NandGate)
{
	nts::Component4030 component4030("4030");

	component4030.getComponents()[0]->getPin(0)->setState(nts::TRUE);
	component4030.getComponents()[0]->getPin(1)->setState(nts::FALSE);
	component4030.getComponents()[0]->localCompute();
	EXPECT_EQ(component4030.getComponents()[0]->getPin(2)->getState(), nts::TRUE);
}

TEST(Component4030, Compute)
{
	nts::Component4030 component4030("4030");
	nts::ComponentInput input("in");
	nts::ComponentInput input2("in2");
	nts::ComponentOutput output("out");

	component4030.setLink(0, input, 0);
	component4030.setLink(1, input2, 0);
	component4030.setLink(2, output, 0);

	input.getPin(0)->setState(nts::TRUE);
	input2.getPin(0)->setState(nts::FALSE);

	ASSERT_EQ(component4030.getPin(0)->getState(), nts::TRUE);
	ASSERT_EQ(component4030.getPin(1)->getState(), nts::FALSE);
	ASSERT_EQ(component4030.getPin(2)->getState(), nts::UNDEFINED);

	output.compute(0);

	ASSERT_EQ(component4030.getComponents()[0]->getPin(2)->getState(), nts::TRUE);
	EXPECT_EQ(output.getPin(0)->getState(), nts::TRUE);

	input.getPin(0)->setState(nts::TRUE);
	input2.getPin(0)->setState(nts::TRUE);
	output.compute(0);

	EXPECT_EQ(output.getPin(0)->getState(), nts::FALSE);

	input.getPin(0)->setState(nts::FALSE);
	input2.getPin(0)->setState(nts::FALSE);
	output.compute(0);

	EXPECT_EQ(output.getPin(0)->getState(), nts::FALSE);
}

TEST(Component4030, Parsing)
{
	const char *av[] = {"b", PROJECT_PATH"samples/simple_components/4030_xor.nts", "a=1", "b=1"};
	nts::Parser parser(4, av);

	nts::Exec::compute(parser.getComponents());
	EXPECT_EQ(parser.getComponents()[2]->getPin(0)->getState(), nts::FALSE);
	EXPECT_EQ(parser.getComponents()[3]->getPin(2)->getState(), nts::FALSE);
}
