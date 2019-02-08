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
	ComponentNGates(name, 4, 3)
{
}