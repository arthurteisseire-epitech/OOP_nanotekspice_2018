/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Created by Adrien FABRE,
*/

#include "gtest/gtest.h"
#include "Exec.hpp"
#include "FileParser.hpp"
#include "ComponentOr.hpp"

TEST(ComponentOr, Init)
{
	nts::ComponentOr orComp("or");

	EXPECT_EQ(orComp.getPin(0)->getType(), nts::IPin::INPUT);
	EXPECT_EQ(orComp.getPin(0)->getState(), nts::UNDEFINED);

	EXPECT_EQ(orComp.getPin(1)->getType(), nts::IPin::INPUT);
	EXPECT_EQ(orComp.getPin(1)->getState(), nts::UNDEFINED);

	EXPECT_EQ(orComp.getPin(2)->getType(), nts::IPin::OUTPUT);
	EXPECT_EQ(orComp.getPin(2)->getState(), nts::UNDEFINED);
}

static void testLocalCompute(nts::Tristate in1State, nts::Tristate in2State, nts::Tristate expectedOutputState)
{
	nts::ComponentOr componentOr("or");

	componentOr.getPin(0)->setState(in1State);
	componentOr.getPin(1)->setState(in2State);
	componentOr.localCompute();
	EXPECT_EQ(componentOr.getPin(2)->getState(), expectedOutputState);
}

TEST(ComponentOr, LocalCompute)
{
	testLocalCompute(nts::TRUE, nts::TRUE, nts::TRUE);
	testLocalCompute(nts::TRUE, nts::FALSE, nts::TRUE);
	testLocalCompute(nts::FALSE, nts::TRUE, nts::TRUE);
	testLocalCompute(nts::FALSE, nts::FALSE, nts::FALSE);
	testLocalCompute(nts::TRUE, nts::UNDEFINED, nts::TRUE);
	testLocalCompute(nts::UNDEFINED, nts::TRUE, nts::TRUE);
	testLocalCompute(nts::FALSE, nts::UNDEFINED, nts::UNDEFINED);
	testLocalCompute(nts::UNDEFINED, nts::FALSE, nts::UNDEFINED);
	testLocalCompute(nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED);
}

static void testCompute(nts::Tristate in1State, nts::Tristate in2State, nts::Tristate expected)
{
	nts::ComponentOr orComp("or");

	orComp.getPin(0)->setState(in1State);
	orComp.getPin(1)->setState(in2State);
	orComp.localCompute();
	EXPECT_EQ(orComp.getPin(0)->getState(), in1State);
	EXPECT_EQ(orComp.getPin(1)->getState(), in2State);
	EXPECT_EQ(orComp.getPin(2)->getState(), expected);
}

TEST(ComponentOr, Compute)
{
	testCompute(nts::TRUE, nts::TRUE, nts::TRUE);
	testCompute(nts::TRUE, nts::FALSE, nts::TRUE);
	testCompute(nts::FALSE, nts::TRUE, nts::TRUE);
	testCompute(nts::FALSE, nts::FALSE, nts::FALSE);
	testCompute(nts::TRUE, nts::UNDEFINED, nts::TRUE);
	testCompute(nts::UNDEFINED, nts::TRUE, nts::TRUE);
	testCompute(nts::FALSE, nts::UNDEFINED, nts::UNDEFINED);
	testCompute(nts::UNDEFINED, nts::FALSE, nts::UNDEFINED);
	testCompute(nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED);
}

TEST(ComponentOr, Parsing)
{
	nts::FileParser fileParser(PROJECT_PATH"samples/gates/or.nts");

	EXPECT_EQ(fileParser.getComponents()[0]->getPin(0)->getState(), nts::UNDEFINED);
	EXPECT_EQ(fileParser.getComponents()[1]->getPin(0)->getState(), nts::UNDEFINED);
	EXPECT_EQ(fileParser.getComponents()[2]->getPin(0)->getState(), nts::UNDEFINED);
	EXPECT_EQ(fileParser.getComponents()[3]->getPin(0)->getState(), nts::UNDEFINED);
	EXPECT_EQ(fileParser.getComponents()[3]->getPin(1)->getState(), nts::UNDEFINED);
	EXPECT_EQ(fileParser.getComponents()[3]->getPin(2)->getState(), nts::UNDEFINED);

	fileParser.getComponents()[0]->getPin(0)->setState(nts::TRUE);
	fileParser.getComponents()[1]->getPin(0)->setState(nts::FALSE);

	nts::Exec::compute(fileParser.getComponents());
	EXPECT_EQ(fileParser.getComponents()[2]->getPin(0)->getState(), nts::TRUE);
}