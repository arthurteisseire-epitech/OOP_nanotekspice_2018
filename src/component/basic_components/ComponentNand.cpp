/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentNand.cpp
*/

#include "ComponentNand.hpp"

nts::ComponentNand::ComponentNand(const std::string &name) :
	AComponent(name)
{
	_pins.push_back(std::shared_ptr<IPin>(new PinInput(*this)));
	_pins.push_back(std::shared_ptr<IPin>(new PinInput(*this)));
	_pins.push_back(std::shared_ptr<IPin>(new PinOutput(*this)));
}

void nts::ComponentNand::dump()
{
}

nts::Tristate nts::ComponentNand::localCompute()
{
	_pins[2]->setState(!(_pins[0]->getState() && _pins[1]->getState()));
	return _pins[2]->getState();
}
