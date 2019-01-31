/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** PinInput.cpp
*/

#include "PinInput.hpp"

nts::PinInput::PinInput(std::shared_ptr<nts::PinOutput> &linkedOutput) :
	_type(INPUT),
	_linkedOutput(linkedOutput)
{
}

nts::Tristate nts::PinInput::compute()
{
	return _linkedOutput->compute();
}
