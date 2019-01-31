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
}

nts::Tristate nts::ComponentAnd::compute(size_t pin)
{
	return _pins[pin]->compute(this);
}

void nts::ComponentAnd::dump()
{
}
