/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Component4011.cpp
*/

#include <iostream>
#include "FileParser.hpp"
#include "ComponentNand.hpp"
#include "Component4011.hpp"

nts::Component4011::Component4011(const std::string &name) :
	ACircuit(name)
{
	for (int i = 0; i < 4; ++i)
		_components.push_back(std::make_unique<ComponentNand>("nand" + std::to_string(0)));

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