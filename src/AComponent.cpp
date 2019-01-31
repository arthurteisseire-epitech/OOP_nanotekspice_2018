/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** AComponent.cpp
*/

#include "AComponent.hpp"

nts::AComponent::AComponent(const std::string &name) :
	_name(name)
{
}

void nts::AComponent::setLink(size_t pin, nts::IComponent &other, size_t otherPin)
{
	_pins[pin] = (*dynamic_cast<AComponent *>(&other))._pins[otherPin];
}
