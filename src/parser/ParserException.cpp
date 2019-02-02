/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ParserException.cpp
*/

#include "ParserException.hpp"

nts::ParserException::ParserException(const std::string &message) :
	_message("Parser exception: " + message)
{
}

const char *nts::ParserException::what() const noexcept
{
	return _message.c_str();
}
