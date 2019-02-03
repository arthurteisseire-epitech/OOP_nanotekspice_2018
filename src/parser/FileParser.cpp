/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** FileParser.cpp
*/

#include "FileParser.hpp"
#include "ParserException.hpp"

nts::FileParser::FileParser(const std::string &filename) :
	_file(filename)
{
	if (_file.fail())
		throw std::ifstream::failure("Error with file: " + filename);
	parseFile();
}

void nts::FileParser::parseFile()
{
	goToSection(".chipsets:");
	initChipsets();
	linkChipsets();
}

void nts::FileParser::goToSection(const std::string &section)
{
	std::string line;

	while (std::getline(_file, line))
		if (line.find(section) != std::string::npos)
			return;
	throw ParserException(section + " section not found");
}

void nts::FileParser::initChipsets()
{
	ComponentFactory componentFactory;
	std::string type;
	std::string value;

	while (!_file.eof()) {
		_file >> type;
		while (type[0] == '#')
			_file >> type;
		if (type == ".links:")
			return;
		_file >> value;
		value = value.substr(0, value.find('#'));
		_components.push_back(componentFactory.createComponent(type, value));
	}
	throw ParserException(".links: section not found");
}

void nts::FileParser::linkChipsets()
{
	std::pair<size_t, std::string> pinValue;
	std::pair<size_t, std::string> otherPinValue;

	while (!_file.eof())
		if (setPairs(pinValue, otherPinValue))
			linkComponents(pinValue, otherPinValue);
}

bool nts::FileParser::setPairs(std::pair<size_t, std::string> &pinValue,
                           std::pair<size_t, std::string> &otherPinValue)
{
	std::string link;

	_file >> link;
	if (_file.eof())
		return false;
	pinValue = createPair(link);
	_file >> link;
	otherPinValue = createPair(link);
	return true;
}

void nts::FileParser::linkComponents(const std::pair<size_t, std::string> &pinValue,
                                 const std::pair<size_t, std::string> &otherPinValue) const
{
	for (auto &component : _components)
		if (component->getName() == pinValue.second) {
			linkPins(pinValue, otherPinValue, component);
			return;
		}
}

void nts::FileParser::linkPins(const std::pair<size_t, std::string> &pinValue,
                           const std::pair<size_t, std::string> &otherPinValue,
                           const std::unique_ptr<nts::IComponent> &component) const
{
	for (auto &otherComponent : this->_components)
		if (otherComponent->getName() == otherPinValue.second) {
			component->setLink(pinValue.first, *otherComponent, otherPinValue.first);
			return;
		}
}

std::pair<size_t, std::string> nts::FileParser::createPair(const std::string &link) const
{
	std::pair<size_t, std::string> pinValue;

	pinValue.first = findPin(link);
	pinValue.second = findValue(link);
	return pinValue;
}

size_t nts::FileParser::findPin(const std::string &link) const
{
	try {
		return std::stoul(link.substr(findSepPos(link) + 1)) - 1;
	} catch (const std::invalid_argument &e) {
		throw ParserException(std::string("pins must be valid numbers: error in ") + e.what());
	}
}

std::string nts::FileParser::findValue(const std::string &link) const
{
	return link.substr(0, findSepPos(link));
}

size_t nts::FileParser::findSepPos(const std::string &link) const
{
	size_t pos = link.find(':');

	if (pos == std::string::npos)
		throw ParserException("value and pin must be separated by a ':'");
	return pos;
}

const std::vector<std::unique_ptr<nts::IComponent>> &nts::FileParser::getComponents() const
{
	return _components;
}
