/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** APin.cpp
*/

#include "APin.hpp"


nts::APin::APin(nts::IPin::Type type) : _type(type), _state(UNDEFINED)
{
}

nts::IPin::Type nts::APin::getType() const
{
	return _type;
}

nts::Tristate nts::APin::getState() const
{
	return _state;
}

void nts::APin::setState(Tristate state)
{
	_state = state;
}