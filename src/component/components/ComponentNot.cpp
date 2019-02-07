/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Created by Adrien FABRE,
*/

#include "ComponentNot.hpp"

nts::ComponentNot::ComponentNot(const std::string &name) :
	AComponent(name)
{
	_pins.push_back(std::shared_ptr<IPin>(new PinInput(*this)));
	_pins.push_back(std::shared_ptr<IPin>(new PinOutput(*this)));
}

nts::Tristate nts::ComponentNot::localCompute()
{
	_pins[1]->setState(!_pins[0]->getState());
	return _pins[1]->getState();
}

void nts::ComponentNot::dump()
{
}