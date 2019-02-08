/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** testsComponent4069.cpp
*/

#include "gtest/gtest.h"
#include "Parser.hpp"
#include "Exec.hpp"
#include "FileParser.hpp"
#include "ComponentInput.hpp"
#include "ComponentOutput.hpp"
#include "ComponentAnd.hpp"
#include "Component4069.hpp"

TEST(Component4069, Init)
{
	nts::Component4069 component4069("4069");

	for (int i = 0; i < 3; ++i) {
		EXPECT_EQ(component4069.getPin(2 * i), component4069.getComponents()[i]->getPin(0));
		EXPECT_EQ(component4069.getPin(2 * i)->getType(), nts::IPin::INPUT);
		EXPECT_EQ(component4069.getPin(2 * i + 1), component4069.getComponents()[i]->getPin(1));
		EXPECT_EQ(component4069.getPin(2 * i + 1)->getType(), nts::IPin::OUTPUT);
	}
	EXPECT_EQ(component4069.getPin(6), nullptr);
	EXPECT_EQ(component4069.getPin(13), nullptr);
	for (int i = 3; i < 6; ++i) {
		EXPECT_EQ(component4069.getPin(2 * i + 2), component4069.getComponents()[i]->getPin(0));
		EXPECT_EQ(component4069.getPin(2 * i + 2)->getType(), nts::IPin::INPUT);
		EXPECT_EQ(component4069.getPin(2 * i + 1), component4069.getComponents()[i]->getPin(1));
		EXPECT_EQ(component4069.getPin(2 * i + 1)->getType(), nts::IPin::OUTPUT);
	}
}

TEST(Component4069, NandGate)
{
	nts::Component4069 component4069("4069");

	component4069.getComponents()[0]->getPin(0)->setState(nts::TRUE);
	component4069.getComponents()[0]->localCompute();
	EXPECT_EQ(component4069.getComponents()[0]->getPin(1)->getState(), nts::FALSE);
}

TEST(Component4069, Compute)
{
	nts::Component4069 component4069("4069");
	nts::ComponentInput input("in");
	nts::ComponentOutput output("out");

	component4069.setLink(0, input, 0);
	component4069.setLink(1, output, 0);

	output.compute(0);
	EXPECT_EQ(output.getPin(0)->getState(), nts::UNDEFINED);

	input.getPin(0)->setState(nts::TRUE);
	output.compute(0);
	ASSERT_EQ(component4069.getComponents()[0]->getPin(1)->getState(), nts::FALSE);
	EXPECT_EQ(output.getPin(0)->getState(), nts::FALSE);

	input.getPin(0)->setState(nts::FALSE);
	output.compute(0);
	EXPECT_EQ(output.getPin(0)->getState(), nts::TRUE);
}

TEST(Component4069, Parsing)
{
	const char *av[] = {"b", PROJECT_PATH"samples/simple_components/4069_not.nts", "i0=1", "i1=1", "i2=1", "i3=0", "i4=0", "i5=0"};
	nts::Parser parser(8, av);

	nts::Exec::compute(parser.getComponents());
	for (int i = 0; i < 3; ++i) {
		EXPECT_EQ(parser.getComponents()[6 + i]->getPin(0)->getState(), nts::FALSE);
		EXPECT_EQ(parser.getComponents()[0]->getPin(2 * i + 1)->getState(), nts::FALSE);
	}
	for (int i = 0; i < 3; ++i) {
		EXPECT_EQ(parser.getComponents()[i + 10]->getPin(0)->getState(), nts::TRUE);
		EXPECT_EQ(parser.getComponents()[0]->getPin(2 * i + 7)->getState(), nts::TRUE);
	}
}