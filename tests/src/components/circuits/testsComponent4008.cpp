/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** testsComponent4008.cpp
*/

#include "gtest/gtest.h"
#include "Parser.hpp"
#include "Exec.hpp"
#include "FileParser.hpp"
#include "ComponentInput.hpp"
#include "ComponentOutput.hpp"
#include "ComponentAnd.hpp"
#include "Component4008.hpp"

TEST(Component4008, Init)
{
	nts::Component4008 component4008("4008");

	EXPECT_EQ(component4008.getPin(0), component4008.getComponents()[3]->getPin(1));
	EXPECT_EQ(component4008.getPin(1), component4008.getComponents()[2]->getPin(1));
	EXPECT_EQ(component4008.getPin(2), component4008.getComponents()[2]->getPin(0));
	EXPECT_EQ(component4008.getPin(3), component4008.getComponents()[1]->getPin(1));
	EXPECT_EQ(component4008.getPin(4), component4008.getComponents()[1]->getPin(0));
	EXPECT_EQ(component4008.getPin(5), component4008.getComponents()[0]->getPin(1));
	EXPECT_EQ(component4008.getPin(6), component4008.getComponents()[0]->getPin(0));
	EXPECT_EQ(component4008.getPin(7), nullptr);
	EXPECT_EQ(component4008.getPin(8), component4008.getComponents()[0]->getPin(2));
	EXPECT_EQ(component4008.getPin(9), component4008.getComponents()[0]->getPin(3));
	EXPECT_EQ(component4008.getPin(10), component4008.getComponents()[1]->getPin(3));
	EXPECT_EQ(component4008.getPin(11), component4008.getComponents()[2]->getPin(3));
	EXPECT_EQ(component4008.getPin(12), component4008.getComponents()[3]->getPin(3));
	EXPECT_EQ(component4008.getPin(13), component4008.getComponents()[3]->getPin(4));
	EXPECT_EQ(component4008.getPin(14), component4008.getComponents()[3]->getPin(0));
	EXPECT_EQ(component4008.getPin(15), nullptr);
}

TEST(Component4008, ComputeOneAdder)
{
	nts::Component4008 component4008("4008");
	nts::ComponentInput input("in");
	nts::ComponentInput input2("in2");
	nts::ComponentInput cin("cin");
	nts::ComponentOutput output("out");
	nts::ComponentOutput cout("cout");

	component4008.setLink(5, input, 0);
	component4008.setLink(6, input2, 0);
	component4008.setLink(8, cin, 0);
	component4008.setLink(9, output, 0);
	component4008.getComponents()[0]->setLink(4, cout, 0);

	input.getPin(0)->setState(nts::TRUE);
	input2.getPin(0)->setState(nts::FALSE);
	cin.getPin(0)->setState(nts::FALSE);

	ASSERT_EQ(component4008.getPin(5)->getState(), nts::TRUE);
	ASSERT_EQ(component4008.getPin(6)->getState(), nts::FALSE);
	ASSERT_EQ(component4008.getPin(8)->getState(), nts::FALSE);
	ASSERT_EQ(component4008.getPin(10)->getState(), nts::UNDEFINED);
	ASSERT_EQ(component4008.getPin(11)->getState(), nts::UNDEFINED);

	output.compute(0);
	cout.compute(0);
	EXPECT_EQ(output.getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(cout.getPin(0)->getState(), nts::FALSE);

	input.getPin(0)->setState(nts::TRUE);
	input2.getPin(0)->setState(nts::TRUE);
	cin.getPin(0)->setState(nts::TRUE);
	output.compute(0);
	cout.compute(0);
	EXPECT_EQ(output.getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(cout.getPin(0)->getState(), nts::TRUE);

	input.getPin(0)->setState(nts::FALSE);
	input2.getPin(0)->setState(nts::FALSE);
	cin.getPin(0)->setState(nts::FALSE);
	output.compute(0);
	cout.compute(0);
	EXPECT_EQ(output.getPin(0)->getState(), nts::FALSE);
	EXPECT_EQ(cout.getPin(0)->getState(), nts::FALSE);

	input.getPin(0)->setState(nts::TRUE);
	input2.getPin(0)->setState(nts::FALSE);
	cin.getPin(0)->setState(nts::TRUE);
	output.compute(0);
	cout.compute(0);
	EXPECT_EQ(output.getPin(0)->getState(), nts::FALSE);
	EXPECT_EQ(cout.getPin(0)->getState(), nts::TRUE);
}

TEST(Component4008, Parsing)
{
	const char *av[] = {"b", PROJECT_PATH"samples/simple_components/4008_adder.nts", "a0=1", "a1=1", "a2=1", "a3=1",
			    "b0=1", "b1=1", "b2=1", "b3=1", "cin=1"};
	nts::Parser parser(11, av);

	nts::Exec::compute(parser.getComponents());
	EXPECT_EQ(parser.getComponents()[11]->getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(parser.getComponents()[12]->getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(parser.getComponents()[13]->getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(parser.getComponents()[14]->getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(parser.getComponents()[10]->getPin(0)->getState(), nts::TRUE);
}