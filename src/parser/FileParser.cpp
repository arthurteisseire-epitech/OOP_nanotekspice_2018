/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** FileParser.cpp
*/

#include "FileParser.hpp"
#include "ParserException.hpp"
#include "PinValue.hpp"

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
	pinValue = nts::PinValue::create(link);
	_file >> link;
	otherPinValue = nts::PinValue::create(link);
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

const std::vector<std::unique_ptr<nts::IComponent>> &nts::FileParser::getComponents() const
{
	return _components;
}
