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
	_components.push_back(std::make_unique<ComponentAnd>("and" + std::to_string(0)));

	_pins.push_back(_components[0]->getPin(0));
	_pins.push_back(_components[0]->getPin(1));
	_pins.push_back(_components[0]->getPin(2));
//	pushInput(0, 0);
//
//	pushInput(0, 1);

//	pushOutput(0);
}

void nts::Component4081::pushInput(size_t componentIdx, size_t componentPin)
{
	_pins.push_back(std::make_shared<PinInput>(*_components[componentIdx]));
//			std::dynamic_pointer_cast<PinOutput>(_components[componentIdx]->getPin(componentPin))));
}

void nts::Component4081::pushOutput(size_t componentIdx)
{
	_pins.push_back(std::make_shared<PinOutput>(*_components[componentIdx]));
}

nts::Tristate nts::Component4081::localCompute()
{
	return nts::UNDEFINED;
}

void nts::Component4081::dump()
{
}
