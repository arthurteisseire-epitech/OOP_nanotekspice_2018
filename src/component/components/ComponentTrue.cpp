/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentTrue.cpp
*/

#include "ComponentTrue.hpp"

nts::ComponentTrue::ComponentTrue(const std::string &name) :
	AComponent(name)
{
	_pins.push_back(std::shared_ptr<IPin>(new PinOutput(*this)));
	_pins[0]->setState(nts::TRUE);
}

void nts::ComponentTrue::dump()
{
}

nts::Tristate nts::ComponentTrue::localCompute()
{
	return nts::TRUE;
}
