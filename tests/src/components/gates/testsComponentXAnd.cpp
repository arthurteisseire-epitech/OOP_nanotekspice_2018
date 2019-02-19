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
#include "ComponentXAnd.hpp"

TEST(ComponentXAnd, Init)
{
	nts::ComponentXAnd XAndComp("XAnd", 4);

	Utils::testInitComp(XAndComp, 3, 1);
}

static void testLocalCompute(nts::Tristate in1State, nts::Tristate in2State, nts::Tristate in3State,
			     nts::Tristate expectedOutputState)
{
	nts::ComponentXAnd XAndComp("XAnd", 3);

	XAndComp.getPin(0)->setState(in1State);
	XAndComp.getPin(1)->setState(in2State);
	XAndComp.getPin(2)->setState(in3State);
	XAndComp.localCompute();
	EXPECT_EQ(XAndComp.getPin(3)->getState(), expectedOutputState);
}

TEST(ComponentXAnd, LocalCompute)
{
	testLocalCompute(nts::TRUE, nts::TRUE, nts::TRUE, nts::TRUE);
	testLocalCompute(nts::TRUE, nts::FALSE, nts::FALSE, nts::FALSE);
	testLocalCompute(nts::FALSE, nts::TRUE, nts::FALSE, nts::FALSE);
	testLocalCompute(nts::FALSE, nts::FALSE, nts::TRUE, nts::FALSE);
	testLocalCompute(nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE);
	testLocalCompute(nts::TRUE, nts::TRUE, nts::UNDEFINED, nts::UNDEFINED);
	testLocalCompute(nts::FALSE, nts::UNDEFINED, nts::UNDEFINED, nts::FALSE);
	testLocalCompute(nts::UNDEFINED, nts::UNDEFINED, nts::FALSE, nts::FALSE);
	testLocalCompute(nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED);
}

static void testCompute(nts::Tristate in1State, nts::Tristate in2State, nts::Tristate expectedOutputState)
{
	nts::ComponentInput in1("in1");
	nts::ComponentInput in2("in2");
	nts::ComponentOutput out("out");
	nts::ComponentXAnd XAndComp("XAnd", 2);

	out.setLink(0, XAndComp, 2);
	XAndComp.setLink(0, in1, 0);
	XAndComp.setLink(1, in2, 0);

	in1.getPin(0)->setState(in1State);
	in2.getPin(0)->setState(in2State);
	EXPECT_EQ(out.getPin(0)->getState(), nts::UNDEFINED);
	out.compute(0);
	EXPECT_EQ(out.getPin(0)->getState(), expectedOutputState);
}

TEST(XAndCompute, Compute)
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