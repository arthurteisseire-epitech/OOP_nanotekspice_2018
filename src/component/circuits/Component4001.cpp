/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Component4001.cpp
*/

#include <iostream>
#include "FileParser.hpp"
#include "Component4001.hpp"
#include "ComponentNor.hpp"

nts::Component4001::Component4001(const std::string &name) :
	ACircuit(name)
{
	for (int i = 0; i < 4; ++i)
		_components.push_back(std::make_unique<ComponentNor>("nor" + std::to_string(0)));

	_pins.push_back(_components[0]->getPin(0));
	_pins.push_back(_components[0]->getPin(1));
	_pins.push_back(_components[0]->getPin(2));

	_pins.push_back(_components[1]->getPin(2));
	_pins.push_back(_components[1]->getPin(1));
	_pins.push_back(_components[1]->getPin(0));

	_pins.push_back(nullptr);

	_pins.push_back(_components[2]->getPin(0));
	_pins.push_back(_components[2]->getPin(1));
	_pins.push_back(_components[2]->getPin(2));

	_pins.push_back(_components[3]->getPin(2));
	_pins.push_back(_components[3]->getPin(1));
	_pins.push_back(_components[3]->getPin(0));
}

nts::Tristate nts::Component4001::localCompute()
{
	return nts::UNDEFINED;
}

void nts::Component4001::dump()
{
}
