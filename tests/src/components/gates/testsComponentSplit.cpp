/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** testsSplitComponent.cpp
*/

#include "gtest/gtest.h"
#include "ComponentInput.hpp"
#include "Exec.hpp"
#include "FileParser.hpp"
#include "ComponentSplit.hpp"
#include "ComponentOutput.hpp"
#include "ComponentAnd.hpp"

TEST(ComponentSplit, Init)
{
	nts::ComponentSplit componentSplit("split", 2);

	EXPECT_EQ(componentSplit.getPin(0)->getState(), nts::UNDEFINED);
	EXPECT_EQ(componentSplit.getPin(0)->getType(), nts::IPin::INPUT);
	EXPECT_EQ(componentSplit.getPin(1)->getState(), nts::UNDEFINED);
	EXPECT_EQ(componentSplit.getPin(1)->getType(), nts::IPin::OUTPUT);
	EXPECT_EQ(componentSplit.getPin(2)->getState(), nts::UNDEFINED);
	EXPECT_EQ(componentSplit.getPin(2)->getType(), nts::IPin::OUTPUT);
}

TEST(ComponentSplit, LocalCompute)
{
	nts::ComponentSplit componentSplit("split", 2);

	componentSplit.getPin(0)->setState(nts::TRUE);
	EXPECT_EQ(componentSplit.localCompute(), nts::TRUE);
	EXPECT_EQ(componentSplit.getPin(1)->getState(), nts::TRUE);
	EXPECT_EQ(componentSplit.getPin(2)->getState(), nts::TRUE);
}

TEST(ComponentSplit, Compute)
{
	nts::ComponentOutput componentOutput("out");
	nts::ComponentOutput componentOutput2("out2");
	nts::ComponentInput input("in");
	nts::ComponentSplit componentSplit("split", 2);

	componentSplit.setLink(0, input, 0);
	componentSplit.setLink(1, componentOutput, 0);
	componentSplit.setLink(2, componentOutput2, 0);

	input.getPin(0)->setState(nts::TRUE);

	componentOutput.compute(0);
	EXPECT_EQ(componentOutput.getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(componentOutput2.getPin(0)->getState(), nts::TRUE);
}

TEST(ComponentSplit, ComputeWithAndGateAndOtherInput)
{
	nts::ComponentOutput componentOutput("out");
	nts::ComponentInput input("in");
	nts::ComponentInput input2("in2");
	nts::ComponentSplit componentSplit("split", 1);
	nts::ComponentAnd componentAnd("and");

	componentSplit.setLink(0, input, 0);
	componentSplit.setLink(1, componentAnd, 0);
	input2.setLink(0, componentAnd, 1);
	componentAnd.setLink(2, componentOutput, 0);

	input.getPin(0)->setState(nts::TRUE);
	input2.getPin(0)->setState(nts::TRUE);

	componentOutput.compute(0);
	EXPECT_EQ(input.getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(input2.getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(componentOutput.getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(componentAnd.getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(componentAnd.getPin(1)->getState(), nts::TRUE);
	EXPECT_EQ(componentAnd.getPin(2)->getState(), nts::TRUE);
	EXPECT_EQ(componentSplit.getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(componentSplit.getPin(1)->getState(), nts::TRUE);
}

TEST(ComponentSplit, ComputeWithAndGate)
{
	nts::ComponentOutput componentOutput("out");
	nts::ComponentInput input("in");
	nts::ComponentSplit componentSplit("split", 2);
	nts::ComponentAnd componentAnd("and");

	componentSplit.setLink(0, input, 0);
	componentAnd.setLink(0, componentSplit, 1);
	componentAnd.setLink(1, componentSplit, 2);
	componentOutput.setLink(0, componentAnd, 2);

	input.getPin(0)->setState(nts::TRUE);

	componentOutput.compute(0);
	EXPECT_EQ(input.getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(componentSplit.getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(componentSplit.getPin(1)->getState(), nts::TRUE);
	EXPECT_EQ(componentSplit.getPin(2)->getState(), nts::TRUE);
	EXPECT_EQ(componentAnd.getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(componentAnd.getPin(1)->getState(), nts::TRUE);
	EXPECT_EQ(componentAnd.getPin(2)->getState(), nts::TRUE);
	EXPECT_EQ(componentOutput.getPin(0)->getState(), nts::TRUE);
}