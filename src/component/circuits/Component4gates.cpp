/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Component4gates.cpp
*/

#include <iostream>
#include "FileParser.hpp"
#include "ComponentAnd.hpp"
#include "ComponentNand.hpp"
#include "ComponentOr.hpp"
#include "ComponentNor.hpp"
#include "ComponentXor.hpp"
#include "ComponentNot.hpp"
#include "Component4gates.hpp"

template<typename GateType>
nts::Component4gates<GateType>::Component4gates(const std::string &name) :
	ACircuit(name)
{
	for (int i = 0; i < 4; ++i)
		_components.push_back(std::make_unique<GateType>("gate" + std::to_string(0)));

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

template
class nts::Component4gates<nts::ComponentAnd>;

template
class nts::Component4gates<nts::ComponentOr>;

template
class nts::Component4gates<nts::ComponentNand>;

template
class nts::Component4gates<nts::ComponentNor>;

template
class nts::Component4gates<nts::ComponentNot>;

template
class nts::Component4gates<nts::ComponentXor>;