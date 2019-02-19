/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentSplit.cpp,
*/

#include <iostream>
#include "ComponentSplit.hpp"

nts::ComponentSplit::ComponentSplit(const std::string &name, size_t signal_split) :
	AComponent(name),
	_splitNb(signal_split)
{
	_pins.push_back(std::make_shared<PinInput>(*this));
	for (size_t i = 0; i < _splitNb; ++i)
		_pins.push_back(std::make_shared<PinOutput>(*this));
}

void nts::ComponentSplit::dump()
{
}

nts::Tristate nts::ComponentSplit::localCompute()
{
	for (size_t i = 1; i < _splitNb + 1; ++i)
		_pins[i]->setState(_pins[0]->getState());
	return _pins[0]->getState();
}