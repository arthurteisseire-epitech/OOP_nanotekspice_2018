/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentAnd.cpp
*/

#include "PinInput.hpp"
#include "ComponentAnd.hpp"

nts::ComponentAnd::ComponentAnd(const std::string &name) :
	AComponent(name)
{
	_pins.push_back(std::shared_ptr<IPin>(new PinInput()));
	_pins.push_back(std::shared_ptr<IPin>(new PinInput()));
	_pins.push_back(std::shared_ptr<IPin>(new PinOutput()));
}

void nts::ComponentAnd::dump()
{
}

nts::Tristate nts::ComponentAnd::local_compute()
{
	_pins[2]->setState(_pins[0]->getState() && _pins[1]->getState());
	return _pins[2]->getState();
}
