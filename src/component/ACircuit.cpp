/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ACircuit.cpp
*/

#include "ACircuit.hpp"
#include "ComponentException.hpp"

nts::ACircuit::ACircuit(const std::string &name) :
	AComponent(name)
{
}

nts::Tristate nts::ACircuit::localCompute()
{
	throw ComponentException("localCompute Circuit aren't supposed to be used");
}