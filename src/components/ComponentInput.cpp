/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentInput.cpp
*/

#include "ComponentInput.hpp"

nts::ComponentInput::ComponentInput(const std::string &name) :
	AComponent(name)
{
}

void nts::ComponentInput::dump()
{
}

nts::Tristate nts::ComponentInput::local_compute()
{
	return _pins[0]->getState();
}
