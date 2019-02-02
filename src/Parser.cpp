/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Parser.cpp
*/

#include <sstream>
#include <zconf.h>
#include "ComponentInput.hpp"
#include "ParserException.hpp"
#include "Parser.hpp"

nts::Parser::Parser(const std::string &filename) :
	_file(filename)
{
	if (_file.fail())
		throw std::ifstream::failure("Error with file: " + filename);
	parserFile();
}

void nts::Parser::parserFile()
{
	goToSection(".chipsets:");
	initChipsets();
	linkChipsets();
}

void nts::Parser::goToSection(const std::string &section)
{
	std::string line;

	while (std::getline(_file, line))
		if (line.find(section) != std::string::npos)
			return;
	throw ParserException(section + " section not found");
}

void nts::Parser::initChipsets()
{
	std::string type;
	std::string value;

	while (!_file.eof()) {
		_file >> type;
		if (type == ".links:")
			return;
		_file >> value;
		_components.push_back(_componentFactory.createComponent(type, value));
	}
	throw ParserException(".links: section not found");
}

void nts::Parser::linkChipsets()
{
	std::pair<size_t, std::string> pinValue;
	std::pair<size_t, std::string> otherPinValue;

	setPairs(pinValue, otherPinValue);
	linkComponents(pinValue, otherPinValue);
}

void nts::Parser::setPairs(std::pair<size_t, std::string> &pinValue,
                           std::pair<size_t, std::string> &otherPinValue)
{
	std::string link;

	_file >> link;
	pinValue = createPair(link);
	_file >> link;
	otherPinValue = createPair(link);
}

void nts::Parser::linkComponents(const std::pair<size_t, std::string> &pinValue,
                                 const std::pair<size_t, std::string> &otherPinValue) const
{
	for (auto &component : _components)
		if (component->getName() == pinValue.second)
			link(pinValue, otherPinValue, component);
}

void nts::Parser::link(const std::pair<size_t, std::string> &pinValue,
                       const std::pair<size_t, std::string> &otherPinValue,
                       const std::unique_ptr<nts::IComponent> &component) const
{
	for (auto &otherComponent : this->_components)
		if (otherComponent->getName() == otherPinValue.second)
			component->setLink(pinValue.first, *otherComponent, otherPinValue.first);
}

std::pair<size_t, std::string> nts::Parser::createPair(const std::string &link) const
{
	std::pair<size_t, std::string> pinValue;

	pinValue.first = findPin(link);
	pinValue.second = findValue(link);
	return pinValue;
}

size_t nts::Parser::findPin(const std::string &link) const
{
	return std::stoul(link.substr(findSepPos(link) + 1)) - 1;
}

std::string nts::Parser::findValue(const std::string &link) const
{
	return link.substr(0, findSepPos(link));
}

size_t nts::Parser::findSepPos(const std::string &link) const
{
	size_t pos = link.find(':');

	if (pos == std::string::npos)
		throw ParserException("value and pin must be separated by a ':'");
	return pos;
}

const std::vector<std::unique_ptr<nts::IComponent>> &nts::Parser::getComponents() const
{
	return _components;
}
