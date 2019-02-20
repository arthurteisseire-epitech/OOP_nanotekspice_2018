/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentFlipFlop.cpp
*/

#include "ComponentFlipFlop.hpp"

nts::ComponentFlipFlop::ComponentFlipFlop(const std::string &name) :
	AComponent(name)
{
	_pins.push_back(std::make_shared<PinOutput>(*this));
	_pins.push_back(std::make_shared<PinOutput>(*this));
	_pins.push_back(std::make_shared<PinInput>(*this));
	_pins.push_back(std::make_shared<PinInput>(*this));
	_pins.push_back(std::make_shared<PinInput>(*this));
	_pins.push_back(std::make_shared<PinInput>(*this));
}

void nts::ComponentFlipFlop::dump()
{
}

void nts::ComponentFlipFlop::changeOutputState()
{
	_pins[1]->setState(nts::FALSE);
	_pins[0]->setState(nts::FALSE);
	if (_pins[3]->getState() == nts::TRUE)
		_pins[1]->setState(nts::TRUE);
	if (_pins[5]->getState() == nts::TRUE)
		_pins[0]->setState(nts::TRUE);
}

// man 4013 pdf

nts::Tristate nts::ComponentFlipFlop::localCompute()
{
	if (_pins[3]->getState() == nts::TRUE || _pins[5]->getState() == nts::TRUE) {
		changeOutputState();
		return (_pins[0]->getState());
	}
	if (_pins[2]->getState() == nts::FALSE)
		return (_pins[0]->getState());
	if (_pins[4]->getState() == nts::TRUE) {
		_pins[0]->setState(nts::TRUE);
		_pins[1]->setState(nts::FALSE);
		return (_pins[0]->getState());
	}
	_pins[0]->setState(nts::FALSE);
	_pins[1]->setState(nts::TRUE);
	return (_pins[0]->getState());
}