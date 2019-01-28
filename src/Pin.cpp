/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Pin.cpp
*/

#include "Pin.hpp"

nts::Pin::Pin(const std::string &name, nts::Tristate input, nts::Tristate output) :
	_name(name),
	_input(input),
	_output(output)
{
}
