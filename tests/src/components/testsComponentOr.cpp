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

TEST(ComponentOr, init)
{
	nts::ComponentOr orComp("or");

	EXPECT_EQ(orComp.getPin(0)->getType(), nts::IPin::INPUT);
	EXPECT_EQ(orComp.getPin(0)->getState(), nts::UNDEFINED);

	EXPECT_EQ(orComp.getPin(1)->getType(), nts::IPin::INPUT);
	EXPECT_EQ(orComp.getPin(1)->getState(), nts::UNDEFINED);

	EXPECT_EQ(orComp.getPin(2)->getType(), nts::IPin::OUTPUT);
	EXPECT_EQ(orComp.getPin(2)->getState(), nts::UNDEFINED);
}

static void testPinState(nts::Tristate in1State, nts::Tristate in2State)
{
	nts::ComponentOr orComp("or");

	orComp.getPin(0)->setState(in1State);
	orComp.getPin(1)->setState(in2State);
	orComp.localCompute();
	EXPECT_EQ(orComp.getPin(0)->getState(), in1State);
	EXPECT_EQ(orComp.getPin(1)->getState(), in2State);
	EXPECT_EQ(orComp.getPin(2)->getState(), in2State || in1State);
}

TEST(ComponentOr, pinState)
{
	testPinState(nts::TRUE, nts::TRUE);
	testPinState(nts::TRUE, nts::FALSE);
	testPinState(nts::FALSE, nts::TRUE);
	testPinState(nts::FALSE, nts::FALSE);
	testPinState(nts::TRUE, nts::UNDEFINED);
	testPinState(nts::UNDEFINED, nts::TRUE);
	testPinState(nts::FALSE, nts::UNDEFINED);
	testPinState(nts::UNDEFINED, nts::FALSE);
	testPinState(nts::UNDEFINED, nts::UNDEFINED);
}