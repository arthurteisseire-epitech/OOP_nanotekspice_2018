/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** PinInput.cpp
*/

#include "PinInput.hpp"

nts::PinInput::PinInput() :
	_type(INPUT)
{
}

nts::IPin::Type nts::PinInput::getType() const
{
	return _type;
}
