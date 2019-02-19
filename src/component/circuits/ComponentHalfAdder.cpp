/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentHalfAdder.cpp
*/

#include <iostream>
#include "ComponentAnd.hpp"
#include "ComponentXor.hpp"
#include "ComponentSplit.hpp"
#include "ComponentHalfAdder.hpp"

nts::ComponentHalfAdder::ComponentHalfAdder(const std::string &name) :
	ACircuit(name)
{
	_components.push_back(std::make_unique<ComponentXor>("xor"));
	_components.push_back(std::make_unique<ComponentAnd>("and"));
	_components.push_back(std::make_unique<ComponentSplit>("split", 2));
	_components.push_back(std::make_unique<ComponentSplit>("split1", 2));
	_pins.push_back(_components[2]->getPin(0));
	_pins.push_back(_components[3]->getPin(0));
	_pins.push_back(_components[0]->getPin(2));
	_pins.push_back(_components[1]->getPin(2));
	_components[0]->setLink(0, *_components[2], 1);
	_components[1]->setLink(0, *_components[2], 2);
	_components[0]->setLink(1, *_components[3], 1);
	_components[1]->setLink(1, *_components[3], 2);
}