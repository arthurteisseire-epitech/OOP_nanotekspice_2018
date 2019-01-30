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
}

void nts::ComponentAnd::setLink(size_t pin, nts::IComponent &other, size_t otherPin)
{
	_pins[pin] = other[otherPin];
}

void nts::ComponentAnd::dump()
{
}
