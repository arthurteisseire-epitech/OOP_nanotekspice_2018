/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** testsTrueComponent.cpp
*/

#include "gtest/gtest.h"
#include "Exec.hpp"
#include "FileParser.hpp"
#include "ComponentTrue.hpp"
#include "ComponentOutput.hpp"

TEST(ComponentTrue, Init)
{
	nts::ComponentTrue componentTrue("true");

	EXPECT_EQ(componentTrue.getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(componentTrue.getPin(0)->getType(), nts::IPin::OUTPUT);
}

TEST(ComponentTrue, LocalCompute)
{
	nts::ComponentTrue componentTrue("true");

	EXPECT_EQ(componentTrue.localCompute(), nts::TRUE);
}

TEST(ComponentTrue, Compute)
{
	nts::ComponentOutput componentOutput("out");
	nts::ComponentTrue componentFalse("false");

	componentFalse.setLink(0, componentOutput, 0);
	componentFalse.compute(0);
	EXPECT_EQ(componentOutput.getPin(0)->getState(), nts::TRUE);
}

TEST(ComponentTrue, Parsing)
{
	nts::FileParser fileParser(PROJECT_PATH"samples/gates/true.nts");
	nts::Exec::compute(fileParser.getComponents());

	EXPECT_EQ(fileParser.getComponents()[0]->getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(fileParser.getComponents()[1]->getPin(0)->getState(), nts::TRUE);
}