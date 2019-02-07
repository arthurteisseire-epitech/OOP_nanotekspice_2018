/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** PinInput.cpp
*/

#include <iostream>
#include "PinException.hpp"
#include "PinInput.hpp"

nts::PinInput::PinInput(IComponent &component, PinOutput *linkedOutput) :
	APin(INPUT, component),
	_linkedOutput(linkedOutput)
{
}

nts::Tristate nts::PinInput::compute()
{
	if (!_linkedOutput)
		throw PinException("Input isn't linked to any output");
	return _linkedOutput->compute();
}

void nts::PinInput::link(std::shared_ptr<PinOutput> toLink)
{
	_linkedOutput = std::move(toLink);
}

const std::shared_ptr<nts::PinOutput> nts::PinInput::getLinkedOutput() const
{
	return _linkedOutput;
}
