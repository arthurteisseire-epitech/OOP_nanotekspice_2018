/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Parser.cpp
*/

#include <iostream>
#include <sstream>
#include "ParserException.hpp"
#include "Parser.hpp"

nts::Parser::Parser(const std::string &filename) :
	_file(filename)
{
	if (_file.fail())
		throw std::ifstream::failure("Error with file: " + filename);
	handleContentErrors();
}

void nts::Parser::handleContentErrors() const
{
	std::stringstream stringstream;
	std::string str;

	stringstream << _file.rdbuf();
	str = stringstream.str();
	if (str.find(".chipsets:") == std::string::npos)
		throw ParserException(".chipsets section not found");
	if (str.find(".links:") == std::string::npos)
		throw ParserException(".links section not found");
}
