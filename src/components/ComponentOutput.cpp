#include <memory>

/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentOutput.cpp
*/

#include <iostream>
#include "PinInput.hpp"
#include "ComponentOutput.hpp"

nts::ComponentOutput::ComponentOutput(const std::string &name) :
	AComponent(name)
{
    _pins.push_back(std::shared_ptr<IPin>(new PinInput(*this)));
}

nts::Tristate nts::ComponentOutput::local_compute()
{
	std::cout << _name << "=" << _pins[0]->getState() << std::endl;
	return _pins[0]->getState();
}

void nts::ComponentOutput::dump()
{
}