/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ParserException.cpp
*/

#include <iostream>
#include "ParserException.hpp"

nts::ParserException::ParserException(const std::string &message) :
	_message(message)
{
}

const char *nts::ParserException::what() const noexcept
{
	return ("Parser file error: " + _message).c_str();
}
