/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** PinInput.cpp
*/

#include "PinInput.hpp"

nts::PinInput::PinInput(std::shared_ptr<PinOutput> linkedOutput) :
	APin(INPUT),
	_linkedOutput(linkedOutput)
{
}

nts::Tristate nts::PinInput::compute()
{
	return _linkedOutput->compute();
}

void nts::PinInput::setLinkedOutput(std::shared_ptr<nts::PinOutput> toLink)
{
	_linkedOutput = toLink;
}

std::shared_ptr<nts::PinOutput> nts::PinInput::getLinkedOutput()
{
	return _linkedOutput;
}
