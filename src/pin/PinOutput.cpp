/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** PinOutput.cpp
*/

#include "PinOutput.hpp"

nts::PinOutput::PinOutput() :
_type(OUTPUT)
{
}

nts::IPin::Type nts::PinOutput::getType() const
{
	return _type;
}
