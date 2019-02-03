/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ArgParser.cpp
*/

#include "ArgParser.hpp"
#include "ParserException.hpp"

nts::ArgParser::ArgParser(int ac, const char *av[])
{
	if (ac == 0)
		throw nts::ParserException(std::string(av[0]) + ": need at least 1 argument");
	_filename = std::string(av[1]);
}

const std::string &nts::ArgParser::getFilename() const
{
	return _filename;
}
