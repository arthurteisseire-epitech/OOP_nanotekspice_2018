/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentOr.cpp
*/

#include "ComponentOr.hpp"

nts::ComponentOr::ComponentOr(const std::string &name) :
	AComponent(name)
{
	_pins.push_back(std::make_shared<PinInput>(*this));
	_pins.push_back(std::make_shared<PinInput>(*this));
	_pins.push_back(std::make_shared<PinOutput>(*this));
}

void nts::ComponentOr::dump()
{
}

nts::Tristate nts::ComponentOr::localCompute()
{
	_pins[2]->setState(_pins[0]->getState() || _pins[1]->getState());
	return _pins[2]->getState();
}
