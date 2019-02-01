/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** PinOutput.cpp
*/

#include <algorithm>
#include <iostream>
#include "PinOutput.hpp"
#include "PinInput.hpp"

nts::PinOutput::PinOutput(IComponent &component) :
    APin(OUTPUT, component)
{
}

nts::Tristate nts::PinOutput::compute()
{
    std::vector<std::shared_ptr<IPin>> pins = _component.getPins();
    for (const auto &pin : pins)
		if (pin->getType() == INPUT)
			pin->compute();
	return _component.local_compute();
}