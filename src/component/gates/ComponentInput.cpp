/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentInput.cpp
*/

#include "ComponentInput.hpp"

nts::ComponentInput::ComponentInput(const std::string &name) :
	AComponent(name)
{
	_type = "input";
	_pins.push_back(std::make_shared<PinOutput>(*this));
}

void nts::ComponentInput::dump()
{
}

nts::Tristate nts::ComponentInput::localCompute()
{
	return _pins[0]->getState();
}
