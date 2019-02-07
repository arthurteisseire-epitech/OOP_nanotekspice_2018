/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentAnd.cpp
*/

#include "ComponentAnd.hpp"

nts::ComponentAnd::ComponentAnd(const std::string &name) :
	AComponent(name)
{
	_pins.push_back(std::shared_ptr<IPin>(new PinInput(*this)));
	_pins.push_back(std::shared_ptr<IPin>(new PinInput(*this)));
	_pins.push_back(std::shared_ptr<IPin>(new PinOutput(*this)));
}

void nts::ComponentAnd::dump()
{
}

nts::Tristate nts::ComponentAnd::localCompute()
{
	_pins[2]->setState(_pins[0]->getState() && _pins[1]->getState());
	return _pins[2]->getState();
}
