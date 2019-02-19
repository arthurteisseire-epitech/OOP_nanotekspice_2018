/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentAdder.cpp
*/

#include "ComponentAdder.hpp"
#include "ComponentHalfAdder.hpp"
#include "ComponentOr.hpp"


nts::ComponentAdder::ComponentAdder(const std::string &name) :
	ACircuit(name)
{
	_components.push_back(std::make_unique<ComponentHalfAdder>("halfAdder"));
	_components.push_back(std::make_unique<ComponentHalfAdder>("halfAdder1"));
	_components.push_back(std::make_unique<ComponentOr>("or"));
	_pins.push_back(_components[0]->getPin(0));
	_pins.push_back(_components[0]->getPin(1));
	_pins.push_back(_components[1]->getPin(1));
	_pins.push_back(_components[1]->getPin(2));
	_pins.push_back(_components[2]->getPin(2));
	_components[0]->setLink(2, *_components[1], 0);
	_components[0]->setLink(3, *_components[2], 0);
	_components[1]->setLink(3, *_components[2], 1);
}