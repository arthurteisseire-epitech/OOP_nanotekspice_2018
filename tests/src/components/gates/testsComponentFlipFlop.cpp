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
#include "ComponentFlipFlop.hpp"

TEST(ComponentFlipFlop, Init)
{
	nts::ComponentFlipFlop FlipFlopComp("FlipFlop");

	Utils::testInitComp(FlipFlopComp, 4, 2);
}

static void testKeepValue(nts::Tristate val1, nts::Tristate val2)
{
	nts::ComponentFlipFlop FlipFlopComp("FlipFlop");

	FlipFlopComp.getPin(0)->setState(val1);
	FlipFlopComp.getPin(1)->setState(val2);
	FlipFlopComp.getPin(2)->setState(nts::FALSE);
	FlipFlopComp.getPin(3)->setState(nts::FALSE);
	FlipFlopComp.getPin(4)->setState(nts::TRUE);
	FlipFlopComp.getPin(5)->setState(nts::FALSE);
	FlipFlopComp.localCompute();
	EXPECT_EQ(FlipFlopComp.getPin(0)->getState(), val1);
	EXPECT_EQ(FlipFlopComp.getPin(1)->getState(), val2);

	FlipFlopComp.getPin(4)->setState(nts::FALSE);
	FlipFlopComp.localCompute();
	EXPECT_EQ(FlipFlopComp.getPin(0)->getState(), val1);
	EXPECT_EQ(FlipFlopComp.getPin(1)->getState(), val2);
}

static void
testLocalCompute(nts::Tristate clock, nts::Tristate data, nts::Tristate reset, nts::Tristate set, nts::Tristate Q,
		 nts::Tristate Qp)
{
	nts::ComponentFlipFlop FlipFlopComp("FlipFlop");

	FlipFlopComp.getPin(2)->setState(clock);
	FlipFlopComp.getPin(3)->setState(reset);
	FlipFlopComp.getPin(4)->setState(data);
	FlipFlopComp.getPin(5)->setState(set);
	FlipFlopComp.localCompute();
	EXPECT_EQ(FlipFlopComp.getPin(0)->getState(), Q);
	EXPECT_EQ(FlipFlopComp.getPin(1)->getState(), Qp);
}

TEST(ComponentFlipFlop, LocalCompute)
{
	testLocalCompute(nts::TRUE, nts::TRUE, nts::TRUE, nts::TRUE, nts::TRUE, nts::TRUE);
	testLocalCompute(nts::FALSE, nts::TRUE, nts::TRUE, nts::TRUE, nts::TRUE, nts::TRUE);
	testLocalCompute(nts::TRUE, nts::FALSE, nts::TRUE, nts::TRUE, nts::TRUE, nts::TRUE);
	testLocalCompute(nts::FALSE, nts::FALSE, nts::TRUE, nts::TRUE, nts::TRUE, nts::TRUE);

	testLocalCompute(nts::TRUE, nts::TRUE, nts::FALSE, nts::TRUE, nts::TRUE, nts::FALSE);
	testLocalCompute(nts::FALSE, nts::TRUE, nts::FALSE, nts::TRUE, nts::TRUE, nts::FALSE);
	testLocalCompute(nts::TRUE, nts::FALSE, nts::FALSE, nts::TRUE, nts::TRUE, nts::FALSE);
	testLocalCompute(nts::FALSE, nts::FALSE, nts::FALSE, nts::TRUE, nts::TRUE, nts::FALSE);

	testLocalCompute(nts::TRUE, nts::TRUE, nts::TRUE, nts::FALSE, nts::FALSE, nts::TRUE);
	testLocalCompute(nts::FALSE, nts::TRUE, nts::TRUE, nts::FALSE, nts::FALSE, nts::TRUE);
	testLocalCompute(nts::TRUE, nts::FALSE, nts::TRUE, nts::FALSE, nts::FALSE, nts::TRUE);
	testLocalCompute(nts::FALSE, nts::FALSE, nts::TRUE, nts::FALSE, nts::FALSE, nts::TRUE);

	testLocalCompute(nts::FALSE, nts::TRUE, nts::FALSE, nts::FALSE, nts::UNDEFINED, nts::UNDEFINED);
	testLocalCompute(nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE, nts::UNDEFINED, nts::UNDEFINED);

	testLocalCompute(nts::TRUE, nts::TRUE, nts::FALSE, nts::FALSE, nts::TRUE, nts::FALSE);

	testLocalCompute(nts::TRUE, nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE, nts::TRUE);

	testKeepValue(nts::TRUE, nts::TRUE);
	testKeepValue(nts::FALSE, nts::TRUE);
	testKeepValue(nts::TRUE, nts::FALSE);
	testKeepValue(nts::FALSE, nts::FALSE);
}

static void testCompute(nts::Tristate clock, nts::Tristate reset, nts::Tristate data, nts::Tristate set,
			nts::Tristate expectedOutput1, nts::Tristate expectedOutput2)
{
	nts::ComponentInput clockC("clock");
	nts::ComponentInput resetC("reset");
	nts::ComponentInput dataC("data");
	nts::ComponentInput setC("set");
	nts::ComponentOutput out("out");
	nts::ComponentOutput out2("out2");
	nts::ComponentFlipFlop FlipFlopComp("FlipFlop");

	out.setLink(0, FlipFlopComp, 0);
	out2.setLink(0, FlipFlopComp, 1);
	FlipFlopComp.setLink(2, clockC, 0);
	FlipFlopComp.setLink(3, resetC, 0);
	FlipFlopComp.setLink(4, dataC, 0);
	FlipFlopComp.setLink(5, setC, 0);

	clockC.getPin(0)->setState(clock);
	resetC.getPin(0)->setState(reset);
	dataC.getPin(0)->setState(data);
	setC.getPin(0)->setState(set);
	out.compute(0);
	EXPECT_EQ(out.getPin(0)->getState(), expectedOutput1);
	EXPECT_EQ(out2.getPin(0)->getState(), expectedOutput2);
}

TEST(FlipFlopCompute, Compute)
{
	testCompute(nts::TRUE, nts::TRUE, nts::TRUE, nts::TRUE, nts::TRUE, nts::TRUE);
	testCompute(nts::FALSE, nts::FALSE, nts::TRUE, nts::TRUE, nts::TRUE, nts::TRUE);

	testCompute(nts::TRUE, nts::TRUE, nts::FALSE, nts::FALSE, nts::TRUE, nts::FALSE);

	testCompute(nts::FALSE, nts::FALSE, nts::TRUE, nts::FALSE, nts::FALSE, nts::TRUE);
}

TEST(ComponentFlipFlop, Parsing)
{
	nts::FileParser fileParser(PROJECT_PATH"samples/gates/FlipFlop.nts");

	EXPECT_EQ(fileParser.getComponents()[0]->getPin(0)->getState(), nts::UNDEFINED);
	EXPECT_EQ(fileParser.getComponents()[1]->getPin(0)->getState(), nts::UNDEFINED);
	EXPECT_EQ(fileParser.getComponents()[2]->getPin(0)->getState(), nts::UNDEFINED);
	EXPECT_EQ(fileParser.getComponents()[3]->getPin(0)->getState(), nts::UNDEFINED);
	EXPECT_EQ(fileParser.getComponents()[4]->getPin(0)->getState(), nts::UNDEFINED);
	EXPECT_EQ(fileParser.getComponents()[4]->getPin(1)->getState(), nts::UNDEFINED);
	EXPECT_EQ(fileParser.getComponents()[4]->getPin(2)->getState(), nts::UNDEFINED);
	EXPECT_EQ(fileParser.getComponents()[4]->getPin(3)->getState(), nts::UNDEFINED);
	EXPECT_EQ(fileParser.getComponents()[4]->getPin(4)->getState(), nts::UNDEFINED);
	EXPECT_EQ(fileParser.getComponents()[4]->getPin(5)->getState(), nts::UNDEFINED);
	EXPECT_EQ(fileParser.getComponents()[5]->getPin(0)->getState(), nts::UNDEFINED);
	EXPECT_EQ(fileParser.getComponents()[6]->getPin(0)->getState(), nts::UNDEFINED);

	fileParser.getComponents()[0]->getPin(0)->setState(nts::TRUE);
	fileParser.getComponents()[1]->getPin(0)->setState(nts::TRUE);
	fileParser.getComponents()[2]->getPin(0)->setState(nts::TRUE);
	fileParser.getComponents()[3]->getPin(0)->setState(nts::TRUE);
	nts::Exec::compute(fileParser.getComponents());
	EXPECT_EQ(fileParser.getComponents()[5]->getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(fileParser.getComponents()[6]->getPin(0)->getState(), nts::TRUE);
}