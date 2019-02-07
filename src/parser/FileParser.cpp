/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** FileParser.cpp
*/

#include <algorithm>
#include <iostream>
#include "FileParser.hpp"
#include "ParserException.hpp"
#include "KeyValue.hpp"

nts::FileParser::FileParser(const std::string &filename) :
	_file(filename)
{
	if (_file.fail())
		throw std::ifstream::failure("Error with file: " + filename);
	parseFile();
	sortComponents();
}

void nts::FileParser::parseFile()
{
	goToSection(".chipsets:");
	initChipsets();
	linkChipsets();
}

void nts::FileParser::sortComponents()
{
	std::sort(this->_components.begin(), this->_components.end(), [](
		std::unique_ptr<nts::IComponent> &c1, std::unique_ptr<nts::IComponent> &c2) {
		return c1->getName() < c2->getName();
	});
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
		type = nextType();
		if (type == ".links:")
			return;
		_file >> value;
		if (value.find(COMMENT_CHAR))
			_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		value = value.substr(0, value.find(COMMENT_CHAR));
		checkExistingName(value);
		_components.push_back(componentFactory.createComponent(type, value));
	}
	throw ParserException(".links: section not found");
}

const std::string nts::FileParser::nextType()
{
	std::string type;

	_file >> type;
	while (type[0] == COMMENT_CHAR) {
		getline(_file, type);
		_file >> type;
	}
	return type;
}

void nts::FileParser::checkExistingName(std::string name)
{
	for (auto &component : _components)
		if (component->getName() == name)
			throw ParserException("Component name '" + name + "' already exists");
}

void nts::FileParser::linkChipsets()
{
	std::pair<std::string, size_t> namePin;
	std::pair<std::string, size_t> otherNamePin;

	while (!_file.eof())
		if (setPairs(namePin, otherNamePin))
			linkComponents(namePin, otherNamePin);
}

bool nts::FileParser::setPairs(std::pair<std::string, size_t> &namePin,
			       std::pair<std::string, size_t> &otherNamePin)
{
	std::string link;

	_file >> link;
	if (_file.eof())
		return false;
	namePin = nts::KeyValue::create(link, ":");
	_file >> link;
	otherNamePin = nts::KeyValue::create(link, ":");
	return true;
}

void nts::FileParser::linkComponents(const std::pair<std::string, size_t> &namePin,
				     const std::pair<std::string, size_t> &otherNamePin) const
{
	for (auto &component : _components)
		if (component->getName() == namePin.first) {
			linkPins(namePin, otherNamePin, component);
			return;
		}
}

void nts::FileParser::linkPins(const std::pair<std::string, size_t> &namePin,
			       const std::pair<std::string, size_t> &otherNamePin,
			       const std::unique_ptr<nts::IComponent> &component) const
{
	for (auto &otherComponent : _components)
		if (otherComponent->getName() == otherNamePin.first) {
			checkPin(component, namePin.second - 1);
			checkPin(otherComponent, otherNamePin.second - 1);
			component->setLink(namePin.second - 1, *otherComponent, otherNamePin.second - 1);
			return;
		}
}

void nts::FileParser::checkPin(const std::unique_ptr<nts::IComponent> &component, size_t pin) const
{
	if (pin >= component->getPins().size())
		throw ParserException("Component " + component->getName() + ": Pin out of range");
}

std::vector<std::unique_ptr<nts::IComponent>> &nts::FileParser::getComponents()
{
	return _components;
}
