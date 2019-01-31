/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** PinOutput.cpp
*/

#include <algorithm>
#include "PinOutput.hpp"
#include "PinInput.hpp"

nts::PinOutput::PinOutput(std::shared_ptr<IComponent> &component, size_t idx) :
	_component(component),
	_type(OUTPUT),
	_idx(idx)
{
}

nts::Tristate nts::PinOutput::compute()
{
	for (auto &pin : _component->getPins())
		if (pin->getType() == INPUT)
			pin->compute();
	return _component->local_compute();
}

std::shared_ptr<nts::IComponent> nts::PinOutput::getComponent() const
{
	return _component;
}
