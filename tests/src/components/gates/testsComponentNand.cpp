/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice_2018
** File description:
** Created by Adrien FABRE,
*/

#include "gtest/gtest.h"
#include "Exec.hpp"
#include "FileParser.hpp"
#include "ComponentInput.hpp"
#include "ComponentOutput.hpp"
#include "ComponentNand.hpp"

TEST(ComponentNand, Init)
{
	nts::ComponentNand NandComp("Nand");

	EXPECT_EQ(NandComp.getPin(0)->getType(), nts::IPin::INPUT);
	EXPECT_EQ(NandComp.getPin(0)->getState(), nts::UNDEFINED);

	EXPECT_EQ(NandComp.getPin(1)->getType(), nts::IPin::INPUT);
	EXPECT_EQ(NandComp.getPin(1)->getState(), nts::UNDEFINED);

	EXPECT_EQ(NandComp.getPin(2)->getType(), nts::IPin::OUTPUT);
	EXPECT_EQ(NandComp.getPin(2)->getState(), nts::UNDEFINED);
}

static void testLocalCompute(nts::Tristate in1State, nts::Tristate in2State, nts::Tristate expectedOutputState)
{
	nts::ComponentNand NandComp("Nand");

	NandComp.getPin(0)->setState(in1State);
	NandComp.getPin(1)->setState(in2State);
	NandComp.localCompute();
	EXPECT_EQ(NandComp.getPin(2)->getState(), expectedOutputState);
}

TEST(ComponentNand, LocalCompute)
{
	testLocalCompute(nts::TRUE, nts::TRUE, nts::FALSE);
	testLocalCompute(nts::TRUE, nts::FALSE, nts::TRUE);
	testLocalCompute(nts::FALSE, nts::TRUE, nts::TRUE);
	testLocalCompute(nts::FALSE, nts::FALSE, nts::TRUE);
	testLocalCompute(nts::TRUE, nts::UNDEFINED, nts::UNDEFINED);
	testLocalCompute(nts::UNDEFINED, nts::TRUE, nts::UNDEFINED);
	testLocalCompute(nts::FALSE, nts::UNDEFINED, nts::TRUE);
	testLocalCompute(nts::UNDEFINED, nts::FALSE, nts::TRUE);
	testLocalCompute(nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED);
}

static void testCompute(nts::Tristate in1State, nts::Tristate in2State, nts::Tristate expectedOutputState)
{
	nts::ComponentInput in1("in1");
	nts::ComponentInput in2("in2");
	nts::ComponentOutput out("out");
	nts::ComponentNand NandComp("Nand");

	out.setLink(0, NandComp, 2);
	NandComp.setLink(0, in1, 0);
	NandComp.setLink(1, in2, 0);

	in1.getPin(0)->setState(in1State);
	in2.getPin(0)->setState(in2State);
	out.compute(0);
	EXPECT_EQ(out.getPin(0)->getState(), expectedOutputState);
}

TEST(NandCompute, Compute)
{
	testCompute(nts::TRUE, nts::TRUE, nts::FALSE);
	testCompute(nts::TRUE, nts::FALSE, nts::TRUE);
	testCompute(nts::FALSE, nts::TRUE, nts::TRUE);
	testCompute(nts::FALSE, nts::FALSE, nts::TRUE);
	testCompute(nts::TRUE, nts::UNDEFINED, nts::UNDEFINED);
	testCompute(nts::UNDEFINED, nts::TRUE, nts::UNDEFINED);
	testCompute(nts::FALSE, nts::UNDEFINED, nts::TRUE);
	testCompute(nts::UNDEFINED, nts::FALSE, nts::TRUE);
	testCompute(nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED);
}

TEST(ComponentNand, Parsing)
{
	nts::FileParser fileParser(PROJECT_PATH"samples/basic_components/nand.nts");

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