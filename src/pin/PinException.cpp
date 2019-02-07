/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** PinException.cpp
*/

#include "PinException.hpp"

nts::PinException::PinException(const std::string &message) :
	_message("Pin exception: " + message)
{
}

const char *nts::PinException::what() const noexcept
{
	return _message.c_str();
}
