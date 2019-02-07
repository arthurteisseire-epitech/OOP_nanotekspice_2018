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
#include "Component4081.hpp"

TEST(Component4081, Init)
{
	nts::Component4081 component4081("4081");

	EXPECT_EQ(component4081.getPin(0), component4081.getComponents()[0]->getPin(0));
	EXPECT_EQ(component4081.getPin(1), component4081.getComponents()[0]->getPin(1));
	EXPECT_EQ(component4081.getPin(2), component4081.getComponents()[0]->getPin(2));
}

TEST(Component4081, AndGateTest)
{
	nts::Component4081 component4081("4081");

	component4081.getComponents()[0]->getPin(0)->setState(nts::TRUE);
	component4081.getComponents()[0]->getPin(1)->setState(nts::TRUE);
	component4081.getComponents()[0]->localCompute();
	EXPECT_EQ(component4081.getComponents()[0]->getPin(2)->getState(), nts::TRUE);
}

TEST(Component4081, Compute)
{
	nts::Component4081 component4081("4081");
	nts::ComponentInput input("in");
	nts::ComponentInput input2("in2");
	nts::ComponentOutput output("out");

	component4081.setLink(0, input, 0);
	component4081.setLink(1, input2, 0);
	component4081.setLink(2, output, 0);

	input.getPin(0)->setState(nts::TRUE);
	input2.getPin(0)->setState(nts::TRUE);

	ASSERT_EQ(component4081.getPin(0)->getState(), nts::TRUE);
	ASSERT_EQ(component4081.getPin(1)->getState(), nts::TRUE);
	ASSERT_EQ(component4081.getPin(2)->getState(), nts::UNDEFINED);

	output.compute(0);
	ASSERT_EQ(component4081.getComponents()[0]->getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(output.getPin(0)->getState(), nts::TRUE);
}
//
//TEST(Component4081, Parsing)
//{
//	const char *av[] = {"b", PROJECT_PATH"samples/simple_components/5input_and.nts", "a=1", "b=1", "c=1", "d=1", "e=1"};
//	nts::Parser parser(7, av);
//
//	nts::Exec::compute(parser.getComponents());
//	EXPECT_EQ(parser.getComponents()[6]->getPin(0)->getState(), nts::TRUE);
//}