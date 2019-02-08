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
#include "Component4071.hpp"

TEST(Component4071, Init)
{
	nts::Component4071 component4071("4071");

	EXPECT_EQ(component4071.getPin(0), component4071.getComponents()[0]->getPin(0));
	EXPECT_EQ(component4071.getPin(1), component4071.getComponents()[0]->getPin(1));
	EXPECT_EQ(component4071.getPin(2), component4071.getComponents()[0]->getPin(2));
}

TEST(Component4071, AndGateTest)
{
	nts::Component4071 component4071("4071");

	component4071.getComponents()[0]->getPin(0)->setState(nts::TRUE);
	component4071.getComponents()[0]->getPin(1)->setState(nts::TRUE);
	component4071.getComponents()[0]->localCompute();
	EXPECT_EQ(component4071.getComponents()[0]->getPin(2)->getState(), nts::TRUE);
	component4071.getComponents()[0]->getPin(0)->setState(nts::FALSE);
	component4071.getComponents()[0]->getPin(1)->setState(nts::FALSE);
	component4071.getComponents()[0]->localCompute();
	EXPECT_EQ(component4071.getComponents()[0]->getPin(2)->getState(), nts::FALSE);
	component4071.getComponents()[0]->getPin(0)->setState(nts::TRUE);
	component4071.getComponents()[0]->getPin(1)->setState(nts::FALSE);
	component4071.getComponents()[0]->localCompute();
	EXPECT_EQ(component4071.getComponents()[0]->getPin(2)->getState(), nts::TRUE);
}

TEST(Component4071, Compute)
{
	nts::Component4071 component4071("4071");
	nts::ComponentInput input("in");
	nts::ComponentInput input2("in2");
	nts::ComponentOutput output("out");

	component4071.setLink(0, input, 0);
	component4071.setLink(1, input2, 0);
	component4071.setLink(2, output, 0);

	input.getPin(0)->setState(nts::TRUE);
	input2.getPin(0)->setState(nts::FALSE);

	ASSERT_EQ(component4071.getPin(0)->getState(), nts::TRUE);
	ASSERT_EQ(component4071.getPin(1)->getState(), nts::FALSE);
	ASSERT_EQ(component4071.getPin(2)->getState(), nts::UNDEFINED);

	output.compute(0);
	ASSERT_EQ(component4071.getComponents()[0]->getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(output.getPin(0)->getState(), nts::TRUE);
}

TEST(Component4071, Parsing)
{
	const char *av[] = {"b", PROJECT_PATH"samples/simple_components/4071_or.nts", "a=1", "b=0"};
	nts::Parser parser(4, av);

	nts::Exec::compute(parser.getComponents());
	EXPECT_EQ(parser.getComponents()[3]->getPin(0)->getState(), nts::TRUE);
}