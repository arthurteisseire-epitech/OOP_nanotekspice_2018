/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Parser.cpp
*/

#include <iostream>
#include "Parser.hpp"

nts::Parser::Parser(const std::string &filename) :
	_file(filename)
{
	_file.open(filename);

	if (_file.fail())
		throw std::exception();
}
