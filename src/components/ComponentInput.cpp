/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentInput.cpp
*/

#include "ComponentInput.hpp"

nts::ComponentInput::ComponentInput(const std::string &name) :
	AComponent(name)
{
}

nts::Tristate nts::ComponentInput::compute(size_t pin)
{
	return _pins[pin]->compute(this);
}

void nts::ComponentInput::dump()
{
}
