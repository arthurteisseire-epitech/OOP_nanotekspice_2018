/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** testsComponent4001.cpp
*/

#include "gtest/gtest.h"
#include "Parser.hpp"
#include "Exec.hpp"
#include "FileParser.hpp"
#include "ComponentInput.hpp"
#include "ComponentOutput.hpp"
#include "ComponentAnd.hpp"
#include "Component4001.hpp"

TEST(Component4001, Init)
{
	nts::Component4001 component4001("4001");

	EXPECT_EQ(component4001.getPin(0), component4001.getComponents()[0]->getPin(0));
	EXPECT_EQ(component4001.getPin(1), component4001.getComponents()[0]->getPin(1));
	EXPECT_EQ(component4001.getPin(2), component4001.getComponents()[0]->getPin(2));
}

TEST(Component4001, NorGate)
{
	nts::Component4001 component4001("4001");

	component4001.getComponents()[0]->getPin(0)->setState(nts::TRUE);
	component4001.getComponents()[0]->getPin(1)->setState(nts::FALSE);
	component4001.getComponents()[0]->localCompute();
	EXPECT_EQ(component4001.getComponents()[0]->getPin(2)->getState(), nts::FALSE);
}

TEST(Component4001, Compute)
{
	nts::Component4001 component4001("4001");
	nts::ComponentInput input("in");
	nts::ComponentInput input2("in2");
	nts::ComponentOutput output("out");

	component4001.setLink(0, input, 0);
	component4001.setLink(1, input2, 0);
	component4001.setLink(2, output, 0);

	input.getPin(0)->setState(nts::TRUE);
	input2.getPin(0)->setState(nts::FALSE);

	ASSERT_EQ(component4001.getPin(0)->getState(), nts::TRUE);
	ASSERT_EQ(component4001.getPin(1)->getState(), nts::FALSE);
	ASSERT_EQ(component4001.getPin(2)->getState(), nts::UNDEFINED);

	output.compute(0);
	ASSERT_EQ(component4001.getComponents()[0]->getPin(2)->getState(), nts::FALSE);
	EXPECT_EQ(output.getPin(0)->getState(), nts::FALSE);
	input.getPin(0)->setState(nts::FALSE);
	input2.getPin(0)->setState(nts::FALSE);
	output.compute(0);
	EXPECT_EQ(output.getPin(0)->getState(), nts::TRUE);
}

TEST(Component4001, Parsing)
{
	const char *av[] = {"b", PROJECT_PATH"samples/simple_components/4001_nor.nts", "a=1", "b=1"};
	nts::Parser parser(4, av);

	nts::Exec::compute(parser.getComponents());
	EXPECT_EQ(parser.getComponents()[2]->getPin(2)->getState(), nts::FALSE);
	EXPECT_EQ(parser.getComponents()[3]->getPin(0)->getState(), nts::FALSE);
}