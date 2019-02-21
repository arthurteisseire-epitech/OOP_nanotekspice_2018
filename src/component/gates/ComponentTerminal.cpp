/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentTerminal.cpp
*/

#include "ComponentTerminal.hpp"

nts::ComponentTerminal::ComponentTerminal(const std::string &name) :
	ComponentOutput(name)
{
	for (int i = 0; i < 9; ++i)
		_pins.push_back(std::make_shared<PinInput>(*this));
}

void nts::ComponentTerminal::dump()
{
}

nts::Tristate nts::ComponentTerminal::compute(size_t pin)
{
	auto state = _pins[pin]->compute();

	localCompute();
	return state;
}

nts::Tristate nts::ComponentTerminal::localCompute()
{
	unsigned char c = 0;

	for (int i = 0; i < 8; ++i)
		c = c << 1 | _pins[i]->getState();
	if (_pins[8]->getState() == nts::TRUE)
		printf("%c", c);
	return _pins[0]->getState();
}