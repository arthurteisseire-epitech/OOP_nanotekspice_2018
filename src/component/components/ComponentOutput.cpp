/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentOutput.cpp
*/

#include "ComponentOutput.hpp"

nts::ComponentOutput::ComponentOutput(const std::string &name) :
	AComponent(name)
{
	_type = "output";
	_pins.push_back(std::shared_ptr<IPin>(new PinInput(*this)));
}

nts::Tristate nts::ComponentOutput::localCompute()
{
	return _pins[0]->getState();
}

void nts::ComponentOutput::dump()
{
}