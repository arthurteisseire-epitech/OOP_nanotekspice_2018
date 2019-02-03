/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** KeyValue.cpp
*/

#include <stdexcept>
#include "KeyValue.hpp"
#include "ParserException.hpp"

std::pair<std::string, size_t> nts::KeyValue::create(const std::string &link, const std::string &sep)
{
	std::pair<std::string, size_t> namePin;

	namePin.first = findName(link, sep);
	namePin.second = findPin(link, sep);
	return namePin;
}

size_t nts::KeyValue::findPin(const std::string &link, const std::string &sep)
{
	try {
		return std::stoul(link.substr(findSepPos(link, sep) + 1));
	} catch (const std::invalid_argument &e) {
		throw ParserException(std::string("pins must be valid numbers: error in ") + e.what());
	}
}

std::string nts::KeyValue::findName(const std::string &link, const std::string &sep)
{
	return link.substr(0, findSepPos(link, sep));
}

size_t nts::KeyValue::findSepPos(const std::string &link, const std::string &sep)
{
	size_t pos = link.find(sep);

	if (pos == std::string::npos)
		throw ParserException("value and pin must be separated by '" + sep + "'");
	return pos;
}