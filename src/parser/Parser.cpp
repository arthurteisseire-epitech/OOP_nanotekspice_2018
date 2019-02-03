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
	std::vector<std::unique_ptr<IComponent>> &components = _fileParser.getComponents();

	for (auto &component : components) {
		if (component->getType() == "input") {
			auto state = static_cast<Tristate>(_argParser.findInputValue(component->getName()));
			component->getPin(0)->setState(state);
		}
	}
}

std::vector<std::unique_ptr<nts::IComponent>> &nts::Parser::getComponents()
{
	return _fileParser.getComponents();
}
