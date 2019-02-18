/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** testsComponent4081.cpp
*/

#include "gtest/gtest.h"
#include "Parser.hpp"
#include "Exec.hpp"
#include "FileParser.hpp"
#include "ComponentInput.hpp"
#include "ComponentOutput.hpp"
#include "ComponentAnd.hpp"
#include "Component4503.hpp"

TEST(Component4503, Init)
{
	nts::Component4503 component4503("4503");

	EXPECT_EQ(component4503.getPin(0), component4503.getComponents()[0]->getPin(0));
	EXPECT_EQ(component4503.getPin(1), component4503.getComponents()[1]->getPin(0));
	EXPECT_EQ(component4503.getPin(2), component4503.getComponents()[1]->getPin(2));
	EXPECT_EQ(component4503.getPin(3), component4503.getComponents()[2]->getPin(0));
	EXPECT_EQ(component4503.getPin(4), component4503.getComponents()[2]->getPin(2));
	EXPECT_EQ(component4503.getPin(5), component4503.getComponents()[3]->getPin(0));
	EXPECT_EQ(component4503.getPin(6), component4503.getComponents()[3]->getPin(2));
	EXPECT_EQ(component4503.getPin(7), nullptr);
	EXPECT_EQ(component4503.getPin(8), component4503.getComponents()[4]->getPin(2));
	EXPECT_EQ(component4503.getPin(9), component4503.getComponents()[4]->getPin(0));
	EXPECT_EQ(component4503.getPin(10), component4503.getComponents()[5]->getPin(2));
	EXPECT_EQ(component4503.getPin(11), component4503.getComponents()[5]->getPin(0));
	EXPECT_EQ(component4503.getPin(12), component4503.getComponents()[6]->getPin(2));
	EXPECT_EQ(component4503.getPin(13), component4503.getComponents()[6]->getPin(0));
	EXPECT_EQ(component4503.getPin(14), component4503.getComponents()[7]->getPin(0));
	EXPECT_EQ(component4503.getPin(15), nullptr);
}

TEST(Component4503, AndGateTest)
{
	nts::Component4503 component4503("4503");

	component4503.getComponents()[1]->getPin(0)->setState(nts::TRUE);
	component4503.getComponents()[1]->getPin(1)->setState(nts::TRUE);
	component4503.getComponents()[1]->localCompute();
	EXPECT_EQ(component4503.getComponents()[1]->getPin(2)->getState(), nts::TRUE);
}

TEST(Component4503, Compute)
{
	nts::Component4503 component4503("4503");
	nts::ComponentInput input("in");
	nts::ComponentInput input2("in2");
	nts::ComponentOutput output("out");

	component4503.setLink(0, input, 0);
	component4503.setLink(1, input2, 0);
	component4503.setLink(2, output, 0);

	input.getPin(0)->setState(nts::TRUE);
	input2.getPin(0)->setState(nts::TRUE);

	ASSERT_EQ(component4503.getPin(0)->getState(), nts::TRUE);
	ASSERT_EQ(component4503.getPin(1)->getState(), nts::TRUE);
	ASSERT_EQ(component4503.getPin(2)->getState(), nts::UNDEFINED);

	output.compute(0);
	EXPECT_EQ(output.getPin(0)->getState(), nts::FALSE);


	input.getPin(0)->setState(nts::FALSE);
	input2.getPin(0)->setState(nts::TRUE);
	output.compute(0);
	EXPECT_EQ(output.getPin(0)->getState(), nts::TRUE);

	input.getPin(0)->setState(nts::FALSE);
	input2.getPin(0)->setState(nts::FALSE);
	output.compute(0);
	EXPECT_EQ(output.getPin(0)->getState(), nts::FALSE);
}

TEST(Component4503, Parsing)
{
	const char *av[] = {"b", PROJECT_PATH"samples/simple_components/4503_non_inverting.nts", "dis1=1", "z0=1",
			    "z1=0", "z2=1", "z3=0", "z4=1", "b0=0", "b1=1", "dis2=0"};
	nts::Parser parser(11, av);

	nts::Exec::compute(parser.getComponents());
	EXPECT_EQ(parser.getComponents()[0]->getPin(0)->getState(), nts::FALSE);
	EXPECT_EQ(parser.getComponents()[1]->getPin(0)->getState(), nts::FALSE);
	EXPECT_EQ(parser.getComponents()[2]->getPin(0)->getState(), nts::FALSE);
	EXPECT_EQ(parser.getComponents()[3]->getPin(0)->getState(), nts::FALSE);
	EXPECT_EQ(parser.getComponents()[4]->getPin(0)->getState(), nts::FALSE);
	EXPECT_EQ(parser.getComponents()[5]->getPin(0)->getState(), nts::TRUE);
}