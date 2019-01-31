/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** testPins.cpp
*/

#include <criterion/criterion.h>
#include <components/ComponentOutput.hpp>
#include <components/ComponentInput.hpp>
#include <iostream>
#include "PinOutput.hpp"
#include "PinInput.hpp"

Test(Pin, initInputPin)
{
	nts::PinInput pin;

	cr_expect_eq(pin.getType(), nts::IPin::INPUT);
	cr_expect_eq(pin.getState(), nts::UNDEFINED);
	cr_expect_eq(pin.getLinkedOutput(), nullptr);
}

Test(Pin, initOutputPin)
{
	nts::PinOutput pin;

	cr_expect_eq(pin.getType(), nts::IPin::OUTPUT);
	cr_expect_eq(pin.getState(), nts::UNDEFINED);
	cr_expect_eq(pin.getComponent(), nullptr);
}

Test(Pin, linkIOPins)
{
    nts::ComponentOutput oComp("o");
	nts::ComponentInput iComp("i");

	oComp.setLink(0, iComp, 0);
	cr_expect_eq(iComp.getPin(0)->getState(), nts::UNDEFINED);
	oComp.getPin(0)->setState(nts::TRUE);
	cr_expect_eq(iComp.getPin(0)->getState(), nts::TRUE);
	cr_expect_eq(oComp.getPin(0)->getState(), nts::TRUE);
}

Test(Pin, linkOIPins)
{
    nts::ComponentOutput oComp("o");
	nts::ComponentInput iComp("i");

	iComp.setLink(0, oComp, 0);
	cr_expect_eq(iComp.getPin(0)->getState(), nts::UNDEFINED);
	iComp.getPin(0)->setState(nts::TRUE);
	cr_expect_eq(iComp.getPin(0)->getState(), nts::TRUE);
	cr_expect_eq(oComp.getPin(0)->getState(), nts::TRUE);
}