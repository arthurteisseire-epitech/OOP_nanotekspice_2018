/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Parser.cpp
*/

#include "Parser.hpp"

nts::Parser::Parser(int ac, const char *av[]) :
	_argParser(ac, av),
	_fileParser(_argParser.getFilename())
{
	setInputsState(_fileParser.getComponents());
}

void nts::Parser::setInputsState(std::vector<std::unique_ptr<nts::IComponent>> &components)
{
	for (auto &component : components) {
		if (component->getType() == "input") {
			auto state = static_cast<nts::Tristate>(_argParser.findInputValue(component->getName()));
			component->getPin(0)->setState(state);
		}
	}
}

std::vector<std::unique_ptr<nts::IComponent>> &nts::Parser::getComponents()
{
	return _fileParser.getComponents();
}

size_t nts::Parser::findInputValue(const std::string &key) const
{
	return _argParser.findInputValue(key);
}

void nts::Parser::setInputValue(const std::string &key, size_t value)
{
	_argParser.setInputValue(key, value);
}

bool nts::Parser::isInputKey(const std::string &key) const
{
	return _argParser.isInputKey(key);
}
