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

void nts::AComponent::setLink(size_t pin, nts::IComponent &other,
    size_t otherPin)
{
    _pins[pin] = other._pins[otherPin];
}
