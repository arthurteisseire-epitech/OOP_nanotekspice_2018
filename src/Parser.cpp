/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Parser.cpp
*/

#include <iostream>
#include <sstream>
#include "Parser.hpp"

nts::Parser::Parser(const std::string &filename) :
	_file(filename)
{
	if (_file.fail())
		throw std::exception();
	handleContentErrors();
}

void nts::Parser::handleContentErrors() const
{
	std::stringstream stringstream;
	std::string str;

	stringstream << _file.rdbuf();
	str = stringstream.str();
	if (str.find(".chipsets") == std::string::npos)
		throw std::exception();
}
