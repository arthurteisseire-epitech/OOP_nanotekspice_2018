/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** AComponent.cpp
*/

#include <iostream>
#include "PinInput.hpp"
#include "PinOutput.hpp"
#include "AComponent.hpp"

nts::AComponent::AComponent(const std::string &name) :
	_name(name)
{
}

void nts::AComponent::setLink(size_t pin, nts::IComponent &other, size_t otherPinIdx)
{
	const std::shared_ptr<IPin> &otherPin = other.getPin(otherPinIdx);
	std::shared_ptr<IPin> &localPin = _pins[pin];
	const IPin::Type &pin1Type = localPin->getType();
	const std::shared_ptr<PinInput> &inputPin = std::static_pointer_cast<PinInput>(pin1Type == IPin::INPUT ? localPin : otherPin);
	const std::shared_ptr<PinOutput> &outputPin = std::static_pointer_cast<PinOutput>(pin1Type != IPin::INPUT ? localPin : otherPin);

	if (pin1Type == otherPin->getType())
		throw;
	localPin = otherPin;
	inputPin->setLinkedOutput(outputPin);
}

const std::shared_ptr<nts::IPin> nts::AComponent::getPin(size_t pin) const
{
	return _pins[pin];
}

const std::vector<std::shared_ptr<nts::IPin>> & nts::AComponent::getPins() const
{
	return _pins;
}

nts::Tristate nts::AComponent::compute(size_t pin)
{
	return _pins[pin]->compute();
}
