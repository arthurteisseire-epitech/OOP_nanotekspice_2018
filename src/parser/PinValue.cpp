/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** PinValue.cpp
*/

#include <stdexcept>
#include "PinValue.hpp"
#include "ParserException.hpp"

std::pair<size_t, std::string> nts::PinValue::create(const std::string &link, const std::string &sep)
{
	std::pair<size_t, std::string> pinValue;

	pinValue.first = findPin(link, sep);
	pinValue.second = findValue(link, sep);
	return pinValue;
}

size_t nts::PinValue::findPin(const std::string &link, const std::string &sep)
{
	try {
		return std::stoul(link.substr(findSepPos(link, sep) + 1)) - 1;
	} catch (const std::invalid_argument &e) {
		throw ParserException(std::string("pins must be valid numbers: error in ") + e.what());
	}
}

std::string nts::PinValue::findValue(const std::string &link, const std::string &sep)
{
	return link.substr(0, findSepPos(link, sep));
}

size_t nts::PinValue::findSepPos(const std::string &link, const std::string &sep)
{
	size_t pos = link.find(sep);

	if (pos == std::string::npos)
		throw ParserException("value and pin must be separated by '" + sep + "'");
	return pos;
}