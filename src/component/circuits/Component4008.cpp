/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Component4008.cpp,
*/

#include "Component4008.hpp"
#include "ComponentAdder.hpp"

nts::Component4008::Component4008(const std::string &name) : ACircuit(name)
{
	_components.push_back(std::make_unique<ComponentAdder>("Adder0"));
	_components.push_back(std::make_unique<ComponentAdder>("Adder1"));
	_components.push_back(std::make_unique<ComponentAdder>("Adder2"));
	_components.push_back(std::make_unique<ComponentAdder>("Adder3"));
	_pins.push_back(_components[3]->getPin(1));
	_pins.push_back(_components[2]->getPin(1));
	_pins.push_back(_components[2]->getPin(0));
	_pins.push_back(_components[1]->getPin(1));
	_pins.push_back(_components[1]->getPin(0));
	_pins.push_back(_components[0]->getPin(1));
	_pins.push_back(_components[0]->getPin(0));
	_pins.push_back(nullptr);
	_pins.push_back(_components[0]->getPin(2));
	_pins.push_back(_components[0]->getPin(3));
	_pins.push_back(_components[1]->getPin(3));
	_pins.push_back(_components[2]->getPin(3));
	_pins.push_back(_components[3]->getPin(3));
	_pins.push_back(_components[3]->getPin(4));
	_pins.push_back(_components[3]->getPin(0));
	_pins.push_back(nullptr);
	_components[0]->setLink(4, *_components[1], 2);
	_components[1]->setLink(4, *_components[2], 2);
	_components[2]->setLink(4, *_components[3], 2);
}