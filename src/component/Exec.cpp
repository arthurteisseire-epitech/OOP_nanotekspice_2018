/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Exec.cpp
*/

#include <iostream>
#include "Exec.hpp"

void nts::Exec::display(const std::vector<std::unique_ptr<IComponent>> &components)
{
	for (auto &component : components)
		if (component->getType() == "output")
			std::cout << component->getName() << "=" << component->getPin(0)->getState() << std::endl;
}

void nts::Exec::compute(const std::vector<std::unique_ptr<nts::IComponent>> &components)
{
	for (auto &component : components)
		if (component->getType() == "output")
			component->compute(0);
}
