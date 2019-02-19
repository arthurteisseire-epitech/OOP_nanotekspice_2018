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
#include "ComponentXOr.hpp"

TEST(ComponentXOr, Init)
{
	nts::ComponentXOr XOrComp("XOr", 4);

	Utils::testInitComp(XOrComp, 3, 1);
}

static void testLocalCompute(nts::Tristate in1State, nts::Tristate in2State, nts::Tristate in3State,
			     nts::Tristate expectedOutputState)
{
	nts::ComponentXOr XOrComp("XOr", 3);

	XOrComp.getPin(0)->setState(in1State);
	XOrComp.getPin(1)->setState(in2State);
	XOrComp.getPin(2)->setState(in3State);
	XOrComp.localCompute();
	EXPECT_EQ(XOrComp.getPin(3)->getState(), expectedOutputState);
}

TEST(ComponentXOr, LocalCompute)
{
	testLocalCompute(nts::TRUE, nts::TRUE, nts::TRUE, nts::TRUE);
	testLocalCompute(nts::TRUE, nts::FALSE, nts::FALSE, nts::TRUE);
	testLocalCompute(nts::FALSE, nts::TRUE, nts::FALSE, nts::TRUE);
	testLocalCompute(nts::FALSE, nts::FALSE, nts::TRUE, nts::TRUE);
	testLocalCompute(nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE);
	testLocalCompute(nts::TRUE, nts::TRUE, nts::UNDEFINED, nts::TRUE);
	testLocalCompute(nts::TRUE, nts::UNDEFINED, nts::UNDEFINED, nts::TRUE);
	testLocalCompute(nts::UNDEFINED, nts::UNDEFINED, nts::TRUE, nts::TRUE);
	testLocalCompute(nts::FALSE, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED);
	testLocalCompute(nts::UNDEFINED, nts::UNDEFINED, nts::FALSE, nts::UNDEFINED);
	testLocalCompute(nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED);
}

static void testCompute(nts::Tristate in1State, nts::Tristate in2State, nts::Tristate expectedOutputState)
{
	nts::ComponentInput in1("in1");
	nts::ComponentInput in2("in2");
	nts::ComponentOutput out("out");
	nts::ComponentXOr XOrComp("XOr", 2);

	out.setLink(0, XOrComp, 2);
	XOrComp.setLink(0, in1, 0);
	XOrComp.setLink(1, in2, 0);

	in1.getPin(0)->setState(in1State);
	in2.getPin(0)->setState(in2State);
	EXPECT_EQ(out.getPin(0)->getState(), nts::UNDEFINED);
	out.compute(0);
	EXPECT_EQ(out.getPin(0)->getState(), expectedOutputState);
}

TEST(XOrCompute, Compute)
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