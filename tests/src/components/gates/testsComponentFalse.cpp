/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** testsTrueComponent.cpp
*/

#include "ComponentFalse.hpp"
#include "ComponentOutput.hpp"
#include "gtest/gtest.h"
#include "Exec.hpp"
#include "FileParser.hpp"

TEST(ComponentFalse, Init)
{
	nts::ComponentFalse f("false");

	EXPECT_EQ(f.getPin(0)->getState(), nts::FALSE);
}

TEST(ComponentFalse, LocalCompute)
{
	nts::ComponentFalse f("false");

	EXPECT_EQ(f.localCompute(), nts::FALSE);
	EXPECT_EQ(f.getPin(0)->getState(), nts::FALSE);
}

TEST(ComponentFalse, Compute)
{
	nts::ComponentOutput componentOutput("out");
	nts::ComponentFalse componentFalse("false");

	componentFalse.setLink(0, componentOutput, 0);
	componentOutput.compute(0);
	EXPECT_EQ(componentOutput.getPin(0)->getState(), nts::FALSE);
}

TEST(ComponentFalse, Parsing)
{
	nts::FileParser fileParser(PROJECT_PATH"samples/gates/false.nts");
	nts::Exec::compute(fileParser.getComponents());

	EXPECT_EQ(fileParser.getComponents()[0]->getPin(0)->getState(), nts::FALSE);
	EXPECT_EQ(fileParser.getComponents()[1]->getPin(0)->getState(), nts::FALSE);
}