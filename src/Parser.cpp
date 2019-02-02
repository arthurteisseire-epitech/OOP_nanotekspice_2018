#include <memory>

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
	handleContentErrors();
}

void nts::Parser::handleContentErrors()
{
	std::stringstream stringstream;
	std::string str;

	stringstream << _file.rdbuf();
	str = stringstream.str();
	if (str.find(".chipsets:") == std::string::npos)
		throw ParserException(".chipsets section not found");
	if (str.find(".links:") == std::string::npos)
		throw ParserException(".links section not found");
	str = str.substr(str.find(".chipsets:"));
	str = nextLine(str);
	str = str.substr(str.find_last_of(" \t") + 1);
	_components.push_back(std::make_shared<ComponentInput>(str));
}

std::string &nts::Parser::nextLine(std::string &str) const
{
	str = str.substr(str.find('\n') + 1);
	str = str.substr(0, str.find('\n'));
	return str;
}

const std::vector<std::shared_ptr<nts::IComponent>> &nts::Parser::getComponents() const
{
	return _components;
}
