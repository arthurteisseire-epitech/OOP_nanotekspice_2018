/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentException.cpp
*/

#include "ComponentException.hpp"

nts::ComponentException::ComponentException(const std::string &message) :
	_message("Component Exception" + message)
{
}

const char *nts::ComponentException::what() const noexcept
{
	return _message.c_str();
}
