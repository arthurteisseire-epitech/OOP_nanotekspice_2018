/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ArgParser.cpp
*/

#include "ArgParser.hpp"
#include "ParserException.hpp"
#include "KeyValue.hpp"

nts::ArgParser::ArgParser(int ac, const char *av[])
{
	if (ac <= 1)
		throw nts::ParserException(std::string(av[0]) + ": need at least 1 argument");
	_filename = std::string(av[1]);

	for (int i = 2; i < ac; ++i)
		_inputs.insert(KeyValue::create(av[i], "="));
}

const std::string &nts::ArgParser::getFilename() const
{
	return _filename;
}

size_t nts::ArgParser::findInputValue(const std::string &key) const
{
	if (_inputs.find(key) == _inputs.end())
		return nts::UNDEFINED;
	return _inputs.at(key);
}

void nts::ArgParser::setInputValue(const std::string &key, size_t value)
{
	_inputs[key] = value;
}