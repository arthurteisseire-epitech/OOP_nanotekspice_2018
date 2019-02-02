/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Parser.cpp
*/

#include <sstream>
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
//	linkChipsets();
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
	std::string chipsetClassName;
	std::string ChipsetName;

	while (!_file.eof()) {
		_file >> chipsetClassName;
		if (chipsetClassName == ".links:")
			return;
		_file >> ChipsetName;
		_components.push_back(std::make_shared<ComponentInput>(ChipsetName));
	}
	throw ParserException(".links: section not found");
}

const std::vector<std::shared_ptr<nts::IComponent>> &nts::Parser::getComponents() const
{
	return _components;
}
