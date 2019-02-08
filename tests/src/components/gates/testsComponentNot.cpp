/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** testsTrueComponent.cpp
*/

#include "gtest/gtest.h"
#include "Exec.hpp"
#include "FileParser.hpp"
#include "ComponentNot.hpp"
#include "ComponentOutput.hpp"
#include "ComponentInput.hpp"

TEST(ComponentNot, Init)
{
	nts::ComponentNot componentNot("not");

	EXPECT_EQ(componentNot.getPin(0)->getState(), nts::UNDEFINED);
	EXPECT_EQ(componentNot.getPin(0)->getType(), nts::IPin::INPUT);
	EXPECT_EQ(componentNot.getPin(1)->getState(), nts::UNDEFINED);
	EXPECT_EQ(componentNot.getPin(1)->getType(), nts::IPin::OUTPUT);
}

static void testLocalCompute(nts::Tristate state, nts::Tristate expected)
{
	nts::ComponentNot NotComp("or");

	NotComp.getPin(0)->setState(state);
	NotComp.localCompute();
	EXPECT_EQ(NotComp.getPin(1)->getState(), expected);
}

TEST(ComponentNot, LocalCompute)
{
	testLocalCompute(nts::TRUE, nts::FALSE);
	testLocalCompute(nts::FALSE, nts::TRUE);
	testLocalCompute(nts::UNDEFINED, nts::UNDEFINED);
}

static void testCompute(nts::Tristate state, nts::Tristate expected)
{
	nts::ComponentNot NotComp("not");
	nts::ComponentInput input("in");
	nts::ComponentOutput output("out");

	input.getPin(0)->setState(state);

	output.setLink(0, NotComp, 1);
	NotComp.setLink(0, input, 0);

	output.compute(0);
	EXPECT_EQ(NotComp.getPin(1)->getState(), expected);
	EXPECT_EQ(output.getPin(0)->getState(), expected);
}

TEST(ComponentNot, Compute)
{
	testCompute(nts::TRUE, nts::FALSE);
	testCompute(nts::FALSE, nts::TRUE);
	testCompute(nts::UNDEFINED, nts::UNDEFINED);
}

TEST(ComponentNot, Parsing)
{
	nts::FileParser fileParser(PROJECT_PATH"samples/basic_components/not.nts");
	nts::Exec::compute(fileParser.getComponents());

	EXPECT_EQ(fileParser.getComponents()[0]->getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(fileParser.getComponents()[1]->getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(fileParser.getComponents()[1]->getPin(1)->getState(), nts::FALSE);
	EXPECT_EQ(fileParser.getComponents()[2]->getPin(0)->getState(), nts::FALSE);
}