/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** testsComponentAdder.cpp
*/

#include "gtest/gtest.h"
#include "Parser.hpp"
#include "Exec.hpp"
#include "FileParser.hpp"
#include "ComponentInput.hpp"
#include "ComponentOutput.hpp"
#include "ComponentAnd.hpp"
#include "ComponentHalfAdder.hpp"

TEST(ComponentHalfAdder, Init)
{
	nts::ComponentHalfAdder componentAdder("Adder");

	EXPECT_EQ(componentAdder.getPin(0)->getType(), nts::IPin::INPUT);
	EXPECT_EQ(componentAdder.getComponents()[2]->getPin(0)->getType(), nts::IPin::INPUT);
	EXPECT_EQ(componentAdder.getComponents()[2]->getPin(1)->getType(), nts::IPin::OUTPUT);
	EXPECT_EQ(componentAdder.getComponents()[2]->getPin(2)->getType(), nts::IPin::OUTPUT);

	EXPECT_EQ(componentAdder.getPin(1)->getType(), nts::IPin::INPUT);
	EXPECT_EQ(componentAdder.getComponents()[3]->getPin(0)->getType(), nts::IPin::INPUT);
	EXPECT_EQ(componentAdder.getComponents()[3]->getPin(1)->getType(), nts::IPin::OUTPUT);
	EXPECT_EQ(componentAdder.getComponents()[3]->getPin(2)->getType(), nts::IPin::OUTPUT);

	EXPECT_EQ(componentAdder.getPin(2)->getType(), nts::IPin::OUTPUT);
	EXPECT_EQ(componentAdder.getComponents()[0]->getPin(2)->getType(), nts::IPin::OUTPUT);

	EXPECT_EQ(componentAdder.getPin(3)->getType(), nts::IPin::OUTPUT);
	EXPECT_EQ(componentAdder.getComponents()[1]->getPin(2)->getType(), nts::IPin::OUTPUT);

	EXPECT_EQ(componentAdder.getComponents()[0]->getName(), "xor");
	EXPECT_EQ(componentAdder.getComponents()[1]->getName(), "and");
}

TEST(ComponentHalfAdder, Compute)
{
	nts::ComponentHalfAdder componentHalfAdder("Adder");
	nts::ComponentInput input("in");
	nts::ComponentInput input2("in2");
	nts::ComponentOutput output("out");
	nts::ComponentOutput cout("cout");

	componentHalfAdder.setLink(0, input, 0);
	componentHalfAdder.setLink(1, input2, 0);
	componentHalfAdder.setLink(2, output, 0);
	componentHalfAdder.setLink(3, cout, 0);

	input.getPin(0)->setState(nts::TRUE);
	input2.getPin(0)->setState(nts::FALSE);

	ASSERT_EQ(componentHalfAdder.getPin(0)->getState(), nts::TRUE);
	ASSERT_EQ(componentHalfAdder.getPin(1)->getState(), nts::FALSE);
	ASSERT_EQ(componentHalfAdder.getPin(2)->getState(), nts::UNDEFINED);

	output.compute(0);
	cout.compute(0);
	ASSERT_EQ(componentHalfAdder.getComponents()[0]->getPin(2)->getState(), nts::TRUE);
	ASSERT_EQ(componentHalfAdder.getComponents()[0]->getPin(3)->getState(), nts::FALSE);
	EXPECT_EQ(output.getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(cout.getPin(0)->getState(), nts::FALSE);

	input.getPin(0)->setState(nts::FALSE);
	input2.getPin(0)->setState(nts::FALSE);
	output.compute(0);
	cout.compute(0);
	EXPECT_EQ(output.getPin(0)->getState(), nts::FALSE);
	EXPECT_EQ(cout.getPin(0)->getState(), nts::FALSE);

	input.getPin(0)->setState(nts::TRUE);
	input2.getPin(0)->setState(nts::TRUE);
	output.compute(0);
	cout.compute(0);
	EXPECT_EQ(output.getPin(0)->getState(), nts::FALSE);
	EXPECT_EQ(cout.getPin(0)->getState(), nts::TRUE);
}

TEST(ComponentHalfAdder, Parsing)
{
	const char *av[] = {"b", PROJECT_PATH"samples/simple_components/half_adder.nts", "a=1", "b=1"};
	nts::Parser parser(4, av);

	nts::Exec::compute(parser.getComponents());
	EXPECT_EQ(parser.getComponents()[2]->getPin(0)->getState(), nts::FALSE);
	EXPECT_EQ(parser.getComponents()[3]->getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(parser.getComponents()[4]->getPin(2)->getState(), nts::FALSE);
	EXPECT_EQ(parser.getComponents()[4]->getPin(3)->getState(), nts::TRUE);
}