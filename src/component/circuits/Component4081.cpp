/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Component4081.cpp
*/

#include <iostream>
#include "FileParser.hpp"
#include "ComponentAnd.hpp"
#include "Component4081.hpp"

nts::Component4081::Component4081(const std::string &name) :
	ACircuit(name)
{
	for (int i = 0; i < 4; ++i)
		_components.push_back(std::make_unique<ComponentAnd>("and" + std::to_string(0)));

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