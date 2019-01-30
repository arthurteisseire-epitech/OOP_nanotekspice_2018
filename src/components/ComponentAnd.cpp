/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentAnd.cpp
*/

#include "ComponentAnd.hpp"

void nts::ComponentAnd::setLink(size_t pin, nts::IComponent &other, size_t otherPin)
{
	_pins[pin] = other[otherPin];
}

nts::ComponentAnd::ComponentAnd(const std::string &name) :
	AComponent(name)
{
}
