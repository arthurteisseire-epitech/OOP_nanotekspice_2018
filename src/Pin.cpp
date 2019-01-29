/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Pin.cpp
*/

#include "Pin.hpp"

nts::Pin::Pin(Tristate state, Type type) : _state(state), _type(type)
{
}

nts::Pin::Type nts::Pin::getType() const
{
    return _type;
}

nts::Tristate nts::Pin::getState() const
{
    return _state;
}
