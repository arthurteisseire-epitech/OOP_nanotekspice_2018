/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice_2018
** File description:
** Created by Adrien FABRE,
*/

#include "gtest/gtest.h"
#include "Utils.hpp"
#include "Exec.hpp"
#include "FileParser.hpp"
#include "ComponentInput.hpp"
#include "ComponentOutput.hpp"
#include "ComponentAnd.hpp"

TEST(ComponentAnd, Init)
{
	nts::ComponentAnd andComp("and");

	Utils::testInitComp(andComp, 2, 1);
}

static void testLocalCompute(nts::Tristate in1State, nts::Tristate in2State, nts::Tristate expectedOutputState)
{
	nts::ComponentAnd andComp("and");

	andComp.getPin(0)->setState(in1State);
	andComp.getPin(1)->setState(in2State);
	andComp.localCompute();
	EXPECT_EQ(andComp.getPin(2)->getState(), expectedOutputState);
}

TEST(ComponentAnd, LocalCompute)
{
	testLocalCompute(nts::TRUE, nts::TRUE, nts::TRUE);
	testLocalCompute(nts::TRUE, nts::FALSE, nts::FALSE);
	testLocalCompute(nts::FALSE, nts::TRUE, nts::FALSE);
	testLocalCompute(nts::FALSE, nts::FALSE, nts::FALSE);
	testLocalCompute(nts::TRUE, nts::UNDEFINED, nts::UNDEFINED);
	testLocalCompute(nts::UNDEFINED, nts::TRUE, nts::UNDEFINED);
	testLocalCompute(nts::FALSE, nts::UNDEFINED, nts::FALSE);
	testLocalCompute(nts::UNDEFINED, nts::FALSE, nts::FALSE);
	testLocalCompute(nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED);
}

static void testCompute(nts::Tristate in1State, nts::Tristate in2State, nts::Tristate expectedOutputState)
{
	nts::ComponentInput in1("in1");
	nts::ComponentInput in2("in2");
	nts::ComponentOutput out("out");
	nts::ComponentAnd andComp("and");

	out.setLink(0, andComp, 2);
	andComp.setLink(0, in1, 0);
	andComp.setLink(1, in2, 0);

	in1.getPin(0)->setState(in1State);
	in2.getPin(0)->setState(in2State);
	EXPECT_EQ(out.getPin(0)->getState(), nts::UNDEFINED);
	out.compute(0);
	EXPECT_EQ(out.getPin(0)->getState(), expectedOutputState);
}

TEST(AndCompute, Compute)
{
	testCompute(nts::TRUE, nts::TRUE, nts::TRUE);
	testCompute(nts::TRUE, nts::FALSE, nts::FALSE);
	testCompute(nts::FALSE, nts::TRUE, nts::FALSE);
	testCompute(nts::FALSE, nts::FALSE, nts::FALSE);
	testCompute(nts::TRUE, nts::UNDEFINED, nts::UNDEFINED);
	testCompute(nts::UNDEFINED, nts::TRUE, nts::UNDEFINED);
	testCompute(nts::FALSE, nts::UNDEFINED, nts::FALSE);
	testCompute(nts::UNDEFINED, nts::FALSE, nts::FALSE);
	testCompute(nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED);
}

TEST(ComponentAnd, Parsing)
{
	nts::FileParser fileParser(PROJECT_PATH"samples/gates/and.nts");

	EXPECT_EQ(fileParser.getComponents()[0]->getPin(0)->getState(), nts::UNDEFINED);
	EXPECT_EQ(fileParser.getComponents()[1]->getPin(0)->getState(), nts::UNDEFINED);
	EXPECT_EQ(fileParser.getComponents()[2]->getPin(0)->getState(), nts::UNDEFINED);
	EXPECT_EQ(fileParser.getComponents()[3]->getPin(0)->getState(), nts::UNDEFINED);
	EXPECT_EQ(fileParser.getComponents()[3]->getPin(1)->getState(), nts::UNDEFINED);
	EXPECT_EQ(fileParser.getComponents()[3]->getPin(2)->getState(), nts::UNDEFINED);

	fileParser.getComponents()[0]->getPin(0)->setState(nts::TRUE);
	fileParser.getComponents()[1]->getPin(0)->setState(nts::FALSE);
	nts::Exec::compute(fileParser.getComponents());
	EXPECT_EQ(fileParser.getComponents()[2]->getPin(0)->getState(), nts::FALSE);
}