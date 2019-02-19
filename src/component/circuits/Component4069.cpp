/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Component4069.cpp
*/

#include <iostream>
#include "Component4069.hpp"

nts::Component4069::Component4069(const std::string &name) :
	ComponentNGates(name, 6, 2, true)
{
	_pins.push_back(nullptr);
}