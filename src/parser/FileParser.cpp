/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** FileParser.cpp
*/

#include "FileParser.hpp"
#include "ParserException.hpp"
#include "NamePin.hpp"

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
	namePin = nts::NamePin::create(link, ":");
	_file >> link;
	otherNamePin = nts::NamePin::create(link, ":");
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
			component->setLink(namePin.second, *otherComponent, otherNamePin.second);
			return;
		}
}

const std::vector<std::unique_ptr<nts::IComponent>> &nts::FileParser::getComponents() const
{
	return _components;
}
