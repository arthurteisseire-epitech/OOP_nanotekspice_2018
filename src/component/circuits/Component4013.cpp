/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Component4013.cpp
*/

#include "Component4013.hpp"
#include "ComponentFlipFlop.hpp"

nts::Component4013::Component4013(const std::string &name) :
	ACircuit(name)
{
	_components.push_back(std::make_unique<ComponentFlipFlop>("flip_flop1"));
	_components.push_back(std::make_unique<ComponentFlipFlop>("flip_flop2"));
	_pins.push_back(_components[0]->getPin(0));
	_pins.push_back(_components[0]->getPin(1));
	_pins.push_back(_components[0]->getPin(2));
	_pins.push_back(_components[0]->getPin(3));
	_pins.push_back(_components[0]->getPin(4));
	_pins.push_back(_components[0]->getPin(5));
	_pins.push_back(nullptr);
	_pins.push_back(_components[1]->getPin(5));
	_pins.push_back(_components[1]->getPin(4));
	_pins.push_back(_components[1]->getPin(3));
	_pins.push_back(_components[1]->getPin(2));
	_pins.push_back(_components[1]->getPin(1));
	_pins.push_back(_components[1]->getPin(0));
	_pins.push_back(nullptr);
}