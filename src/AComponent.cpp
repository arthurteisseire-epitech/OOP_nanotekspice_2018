/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** AComponent.cpp
*/

#include "AComponent.hpp"

nts::AComponent::AComponent(const std::vector<nts::Pin> &pins)
{
}

nts::Pin *nts::AComponent::operator[](size_t pin) const
{
	return _pins[pin];
}
