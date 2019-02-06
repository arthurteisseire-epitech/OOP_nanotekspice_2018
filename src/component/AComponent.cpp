/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** AComponent.cpp
*/

#include "AComponent.hpp"

nts::AComponent::AComponent(const std::string &name) :
	_name(name),
	_type("default")
{
}

const std::shared_ptr<nts::IPin> nts::AComponent::getPin(size_t pin) const
{
	return _pins[pin];
}

const std::vector<std::shared_ptr<nts::IPin>> &nts::AComponent::getPins() const
{
	return _pins;
}

nts::Tristate nts::AComponent::compute(size_t pin)
{
	return _pins[pin]->compute();
}

void nts::AComponent::setLink(size_t pin, nts::IComponent &other, size_t otherPinIdx)
{
	std::shared_ptr<IPin> otherPin = other.getPin(otherPinIdx);
	const std::shared_ptr<IPin> &localPin = _pins[pin];
	std::shared_ptr<PinInput> inputPin = chooseInputPin(localPin, otherPin);
	std::shared_ptr<PinOutput> outputPin = chooseOutputPin(localPin, otherPin);

	if (localPin == inputPin)
		_pins[pin] = other.getPin(otherPinIdx);
	else
		other.setPin(otherPinIdx, _pins[pin]);
	inputPin->link(outputPin);
}

std::shared_ptr<nts::PinInput> nts::AComponent::chooseInputPin(const std::shared_ptr<IPin> &pin1,
							       const std::shared_ptr<nts::IPin> &pin2)
{
	if (pin1->getType() == pin2->getType())
		throw std::exception();
	return std::static_pointer_cast<PinInput>(pin1->getType() == IPin::INPUT ? pin1 : pin2);
}

std::shared_ptr<nts::PinOutput> nts::AComponent::chooseOutputPin(const std::shared_ptr<IPin> &pin1,
								 const std::shared_ptr<nts::IPin> &pin2)
{
	if (pin1->getType() == pin2->getType())
		throw std::exception();
	return std::static_pointer_cast<PinOutput>(pin1->getType() == IPin::OUTPUT ? pin1 : pin2);
}

const std::string &nts::AComponent::getName() const
{
	return _name;
}

const std::string &nts::AComponent::getType() const
{
	return _type;
}

void nts::AComponent::setPin(size_t pin, const std::shared_ptr<nts::IPin> &pinPtr)
{
	_pins[pin] = pinPtr;
}
