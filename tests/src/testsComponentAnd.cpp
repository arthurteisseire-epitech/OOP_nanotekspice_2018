/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice_2018
** File description:
** Created by Adrien FABRE,
*/

#include <gtest/gtest.h>
#include "ComponentAnd.hpp"

TEST(ComponentAnd, init)
{
	nts::ComponentAnd andComp("and");

	EXPECT_EQ(andComp.getPin(0)->getType(), nts::IPin::INPUT);
	EXPECT_EQ(andComp.getPin(0)->getState(), nts::UNDEFINED);

	EXPECT_EQ(andComp.getPin(1)->getType(), nts::IPin::INPUT);
	EXPECT_EQ(andComp.getPin(1)->getState(), nts::UNDEFINED);

	EXPECT_EQ(andComp.getPin(2)->getType(), nts::IPin::OUTPUT);
	EXPECT_EQ(andComp.getPin(2)->getState(), nts::UNDEFINED);
}

static void testPinState(nts::Tristate in1State, nts::Tristate in2State)
{
	nts::ComponentAnd andComp("and");

	andComp.getPin(0)->setState(in1State);
	andComp.getPin(1)->setState(in2State);
	andComp.local_compute();
	EXPECT_EQ(andComp.getPin(0)->getState(), in1State);
	EXPECT_EQ(andComp.getPin(1)->getState(), in2State);
}

TEST(ComponentAnd, pinState)
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