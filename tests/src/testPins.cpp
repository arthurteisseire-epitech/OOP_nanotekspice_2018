/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** testPins.cpp
*/

#include <criterion/criterion.h>
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
