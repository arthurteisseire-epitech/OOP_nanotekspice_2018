/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Component7Seg.cpp
*/

#include "Component7Seg.hpp"

nts::Component7Seg::Component7Seg(const std::string &name) :
	ComponentOutput(name)
{
	for (int i = 0; i < 4; ++i)
		_pins.push_back(std::make_shared<PinInput>(*this));
}

void nts::Component7Seg::dump()
{
}

nts::Tristate nts::Component7Seg::compute(size_t pin)
{
	auto state = _pins[pin]->compute();

	localCompute();
	return state;
}

nts::Tristate nts::Component7Seg::localCompute()
{
	unsigned char c = 0;

	for (int i = 0; i < 4; ++i)
		c = c << 1 | _pins[i]->getState();
	printf("%#x", c);
	return _pins[0]->getState();
}