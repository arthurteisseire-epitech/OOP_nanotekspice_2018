/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** testPins.cpp
*/

#include "gtest/gtest.h"
#include "ComponentOutput.hpp"
#include "ComponentInput.hpp"
#include "PinOutput.hpp"
#include "PinInput.hpp"

TEST(Pin, InitInputPin)
{
	nts::ComponentOutput comp("out");
	const std::shared_ptr<nts::PinInput> pin =
		std::dynamic_pointer_cast<nts::PinInput>(comp.getPin(0));

	EXPECT_EQ(pin->getType(), nts::IPin::INPUT);
	EXPECT_EQ(pin->getState(), nts::UNDEFINED);
	EXPECT_EQ(pin->getLinkedOutput(), nullptr);
}

TEST(Pin, InitOutputPin)
{
	nts::ComponentInput comp("in");
	const std::shared_ptr<nts::PinOutput> pin = std::dynamic_pointer_cast<nts::PinOutput>(
		comp.getPin(0));

	EXPECT_EQ(pin->getType(), nts::IPin::OUTPUT);
	EXPECT_EQ(pin->getState(), nts::UNDEFINED);
	EXPECT_EQ(&pin->getComponent(), &comp);
}

TEST(Pin, LinkIOPins)
{
	nts::ComponentOutput oComp("o");
	nts::ComponentInput iComp("i");

	oComp.setLink(0, iComp, 0);
	EXPECT_EQ(iComp.getPin(0)->getState(), nts::UNDEFINED);
	oComp.getPin(0)->setState(nts::TRUE);
	EXPECT_EQ(iComp.getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(oComp.getPin(0)->getState(), nts::TRUE);
}

TEST(Pin, LinkOIPins)
{
	nts::ComponentOutput oComp("o");
	nts::ComponentInput iComp("i");

	iComp.setLink(0, oComp, 0);
	EXPECT_EQ(iComp.getPin(0)->getState(), nts::UNDEFINED);
	iComp.getPin(0)->setState(nts::TRUE);
	EXPECT_EQ(iComp.getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(oComp.getPin(0)->getState(), nts::TRUE);
}