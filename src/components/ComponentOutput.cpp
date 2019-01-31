/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentOutput.cpp
*/

#include <iostream>
#include "ComponentOutput.hpp"

nts::ComponentOuput::ComponentOuput(const std::string &name) :
	AComponent(name)
{
}

nts::Tristate nts::ComponentOuput::local_compute()
{
	std::cout << _name << "=" << _pins[0]->getState() << std::endl;
	return _pins[0]->getState();
}

void nts::ComponentOuput::dump()
{

}


