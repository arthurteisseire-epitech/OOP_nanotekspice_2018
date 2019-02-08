/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentNGates.cpp
*/

#include <iostream>
#include "FileParser.hpp"
#include "ComponentAnd.hpp"
#include "ComponentNand.hpp"
#include "ComponentOr.hpp"
#include "ComponentNor.hpp"
#include "ComponentXor.hpp"
#include "ComponentNot.hpp"
#include "ComponentNGates.hpp"

template<typename GateType>
nts::ComponentNGates<GateType>::ComponentNGates(const std::string &name, size_t gates_nb, size_t pinsPerGate, bool swap_after_half) :
	ACircuit(name)
{
	for (size_t i = 0; i < gates_nb; ++i) {
		_components.push_back(std::make_unique<GateType>("gate" + std::to_string(0)));
		if (i * pinsPerGate + 1 == 7 || i * pinsPerGate + 1 == 14)
			_pins.push_back(nullptr);
		for (size_t idx = 0; idx < pinsPerGate; ++idx) {
			if (swap_after_half) {
				_pins.push_back(_components[i]->getPin(i < gates_nb / 2 ? idx : pinsPerGate - idx - 1));
			} else
				_pins.push_back(_components[i]->getPin((i & 1) == 0 ? idx : pinsPerGate - idx - 1));
		}
	}
}

template
class nts::ComponentNGates<nts::ComponentAnd>;

template
class nts::ComponentNGates<nts::ComponentOr>;

template
class nts::ComponentNGates<nts::ComponentNand>;

template
class nts::ComponentNGates<nts::ComponentNor>;

template
class nts::ComponentNGates<nts::ComponentNot>;

template
class nts::ComponentNGates<nts::ComponentXor>;