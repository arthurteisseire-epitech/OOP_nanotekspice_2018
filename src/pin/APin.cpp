#include <memory>

/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** APin.cpp
*/

#include "APin.hpp"

nts::APin::APin(nts::IPin::Type type, IComponent &component) :
	_type(type),
	_state(std::make_shared<Tristate>()),
	_component(component)
{
	*_state = UNDEFINED;
}

nts::IPin::Type nts::APin::getType() const
{
	return _type;
}

nts::Tristate nts::APin::getState() const
{
	return *_state;
}

void nts::APin::setState(Tristate state)
{
	*_state = state;
}

const nts::IComponent &nts::APin::getComponent() const
{
	return _component;
}

void nts::APin::linkPin(std::shared_ptr<nts::IPin> pin)
{
	_state = pin->getStatePtr();
}

std::shared_ptr<nts::Tristate> nts::APin::getStatePtr() const
{
	return _state;
}
