/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Component4071.cpp
*/

#include <iostream>
#include "FileParser.hpp"
#include "ComponentAnd.hpp"
#include "Component4071.hpp"

nts::Component4071::Component4071(const std::string &name) :
	ComponentNGates(name, 4, 3)
{
}