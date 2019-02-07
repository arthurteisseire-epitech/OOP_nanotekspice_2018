/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentNor.cpp
*/

#include "ComponentNor.hpp"

nts::ComponentNor::ComponentNor(const std::string &name) :
	AComponent(name)
{
	_pins.push_back(std::shared_ptr<IPin>(new PinInput(*this)));
	_pins.push_back(std::shared_ptr<IPin>(new PinInput(*this)));
	_pins.push_back(std::shared_ptr<IPin>(new PinOutput(*this)));
}

void nts::ComponentNor::dump()
{
}

nts::Tristate nts::ComponentNor::localCompute()
{
	_pins[2]->setState(!(_pins[0]->getState() || _pins[1]->getState()));
	return _pins[2]->getState();
}
