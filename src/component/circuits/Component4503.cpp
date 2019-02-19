/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Component4503.cpp,
*/

#include "Component4503.hpp"
#include "ComponentAnd.hpp"
#include "ComponentNot.hpp"
#include "ComponentSplit.hpp"

nts::Component4503::Component4503(const std::string &name) : ACircuit(name)
{
	_components.push_back(std::make_unique<ComponentNot>("DisableInput1"));
	for (int i = 0; i < 6; ++i)
		_components.push_back(std::make_unique<ComponentAnd>("and" + std::to_string(i + 1)));
	_components.push_back(std::make_unique<ComponentNot>("DisableInput2"));
	_components.push_back(std::make_unique<ComponentSplit>("split1", 4));
	_components.push_back(std::make_unique<ComponentSplit>("split2", 2));

	_pins.push_back(_components[0]->getPin(0));
	for (int i = 1; i < 4; ++i) {
		_pins.push_back(_components[i]->getPin(0));
		_pins.push_back(_components[i]->getPin(2));
	}
	_pins.push_back(nullptr);
	for (int i = 4; i < 7; ++i) {
		_pins.push_back(_components[i]->getPin(2));
		_pins.push_back(_components[i]->getPin(0));
	}
	_pins.push_back(_components[7]->getPin(0));
	_pins.push_back(nullptr);
	_components[0]->setLink(1, *_components[8], 0);
	_components[1]->setLink(1, *_components[8], 1);
	_components[2]->setLink(1, *_components[8], 2);
	_components[3]->setLink(1, *_components[8], 3);
	_components[4]->setLink(1, *_components[8], 4);
	_components[7]->setLink(1, *_components[9], 0);
	_components[6]->setLink(1, *_components[9], 1);
	_components[5]->setLink(1, *_components[9], 2);
}