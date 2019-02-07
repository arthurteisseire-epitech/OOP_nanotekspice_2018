/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Created by Adrien FABRE,
*/

#include "gtest/gtest.h"
#include "Exec.hpp"
#include "FileParser.hpp"
#include "ComponentXor.hpp"

TEST(ComponentXor, Init)
{
	nts::ComponentXor xorComp("xor");

	EXPECT_EQ(xorComp.getPin(0)->getType(), nts::IPin::INPUT);
	EXPECT_EQ(xorComp.getPin(0)->getState(), nts::UNDEFINED);

	EXPECT_EQ(xorComp.getPin(1)->getType(), nts::IPin::INPUT);
	EXPECT_EQ(xorComp.getPin(1)->getState(), nts::UNDEFINED);

	EXPECT_EQ(xorComp.getPin(2)->getType(), nts::IPin::OUTPUT);
	EXPECT_EQ(xorComp.getPin(2)->getState(), nts::UNDEFINED);
}

static void testLocalCompute(nts::Tristate in1State, nts::Tristate in2State, nts::Tristate expectedOutputState)
{
	nts::ComponentXor componentXor("xor");

	componentXor.getPin(0)->setState(in1State);
	componentXor.getPin(1)->setState(in2State);
	componentXor.localCompute();
	EXPECT_EQ(componentXor.getPin(2)->getState(), expectedOutputState);
}

TEST(ComponentXor, LocalCompute)
{
	testLocalCompute(nts::TRUE, nts::TRUE, nts::FALSE);
	testLocalCompute(nts::TRUE, nts::FALSE, nts::TRUE);
	testLocalCompute(nts::FALSE, nts::TRUE, nts::TRUE);
	testLocalCompute(nts::FALSE, nts::FALSE, nts::FALSE);
	testLocalCompute(nts::TRUE, nts::UNDEFINED, nts::UNDEFINED);
	testLocalCompute(nts::UNDEFINED, nts::TRUE, nts::UNDEFINED);
	testLocalCompute(nts::FALSE, nts::UNDEFINED, nts::UNDEFINED);
	testLocalCompute(nts::UNDEFINED, nts::FALSE, nts::UNDEFINED);
	testLocalCompute(nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED);
}

static void testCompute(nts::Tristate in1State, nts::Tristate in2State, nts::Tristate expected)
{
	nts::ComponentXor xorComp("xor");

	xorComp.getPin(0)->setState(in1State);
	xorComp.getPin(1)->setState(in2State);
	xorComp.localCompute();
	EXPECT_EQ(xorComp.getPin(0)->getState(), in1State);
	EXPECT_EQ(xorComp.getPin(1)->getState(), in2State);
	EXPECT_EQ(xorComp.getPin(2)->getState(), expected);
}

TEST(ComponentXor, Compute)
{
	testCompute(nts::TRUE, nts::TRUE, nts::FALSE);
	testCompute(nts::TRUE, nts::FALSE, nts::TRUE);
	testCompute(nts::FALSE, nts::TRUE, nts::TRUE);
	testCompute(nts::FALSE, nts::FALSE, nts::FALSE);
	testCompute(nts::TRUE, nts::UNDEFINED, nts::UNDEFINED);
	testCompute(nts::UNDEFINED, nts::TRUE, nts::UNDEFINED);
	testCompute(nts::FALSE, nts::UNDEFINED, nts::UNDEFINED);
	testCompute(nts::UNDEFINED, nts::FALSE, nts::UNDEFINED);
	testCompute(nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED);
}

TEST(ComponentXor, Parsing)
{
	nts::FileParser fileParser(PROJECT_PATH"samples/basic_components/xor.nts");

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