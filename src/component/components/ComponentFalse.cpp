/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentFalse.cpp
*/

#include "ComponentFalse.hpp"

nts::ComponentFalse::ComponentFalse(const std::string &name) :
	AComponent(name)
{
	_pins.push_back(std::shared_ptr<IPin>(new PinOutput(*this)));
	_pins[0]->setState(nts::FALSE);
}

void nts::ComponentFalse::dump()
{
}

nts::Tristate nts::ComponentFalse::localCompute()
{
	return nts::FALSE;
}
