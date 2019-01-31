/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** AComponent.cpp
*/

#include "PinInput.hpp"
#include "PinOutput.hpp"
#include "AComponent.hpp"

nts::AComponent::AComponent(const std::string &name) :
	_name(name)
{
}

void nts::AComponent::setLink(size_t pin, nts::IComponent &other, size_t otherPin)
{
	_pins[pin] = other.getPins()[otherPin];
	if (_pins[pin]->getType() == IPin::INPUT) {
		std::static_pointer_cast<PinInput>(_pins[pin])->setLinkedOutput(
			std::static_pointer_cast<PinOutput>(other.getPins()[otherPin]));
	} else {
		std::static_pointer_cast<PinInput>(other.getPins()[otherPin])->setLinkedOutput(
			std::static_pointer_cast<PinOutput>(_pins[pin]));
	}
}

const std::shared_ptr<nts::IPin> nts::AComponent::getPin(size_t pin) const
{
	return _pins[pin];
}

const std::vector<std::shared_ptr<nts::IPin>> nts::AComponent::getPins() const
{
	return _pins;
}

nts::Tristate nts::AComponent::compute(size_t pin)
{
	return _pins[pin]->compute();
}
