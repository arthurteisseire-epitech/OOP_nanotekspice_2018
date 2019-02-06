/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** DisplayOutputs.cpp
*/

#include <iostream>
#include "IComponent.hpp"

namespace nts {
	void display(const std::vector<std::unique_ptr<IComponent>> &components)
	{
		for (auto &component : components)
			if (component->getType() == "output")
				std::cout << component->getName() << "=" << component->getPin(0)->getState()
					<< std::endl;
	}
}