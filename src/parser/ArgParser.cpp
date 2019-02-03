/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ArgParser.cpp
*/

#include "ArgParser.hpp"
#include "ParserException.hpp"
#include "NamePin.hpp"

nts::ArgParser::ArgParser(int ac, const char *av[])
{
	if (ac <= 2)
		throw nts::ParserException(std::string(av[0]) + ": need at least 1 argument");
	_filename = std::string(av[1]);

	for (int i = 0; i < ac; ++i)
		_inputs.insert(NamePin::create(av[i], "="));
}

const std::string &nts::ArgParser::getFilename() const
{
	return _filename;
}

size_t nts::ArgParser::findInput(const std::string &key) const
{
	return _inputs.at(key);
}
