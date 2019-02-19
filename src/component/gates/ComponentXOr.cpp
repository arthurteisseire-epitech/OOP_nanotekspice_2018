/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentOr.cpp
*/

#include "ComponentXOr.hpp"

nts::ComponentXOr::ComponentXOr(const std::string &name, int inputNb) :
	AComponent(name),
	_inputNb(inputNb)
{
	for (int i = 0; i < inputNb; ++i)
		_pins.push_back(std::make_shared<PinInput>(*this));
	_pins.push_back(std::make_shared<PinOutput>(*this));
}

void nts::ComponentXOr::dump()
{
}

nts::Tristate nts::ComponentXOr::localCompute()
{
	_pins[_inputNb]->setState(_pins[0]->getState());
	for (int i = 1; i < _inputNb; ++i)
		_pins[_inputNb]->setState(_pins[_inputNb]->getState() || _pins[i]->getState());
	return _pins[_inputNb]->getState();
}
