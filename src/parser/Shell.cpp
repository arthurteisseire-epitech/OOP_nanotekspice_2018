/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Shell.cpp
*/

#include <iostream>
#include "Exec.hpp"
#include "Shell.hpp"
#include "KeyValue.hpp"

nts::Shell::Shell(nts::Parser &parser) :
	_parser(parser)
{
}

void nts::Shell::exec()
{
	std::string word;

	std::cout << "> ";
	while (getline(std::cin, word) && word != "exit") {
		execLine(word);
		std::cout << "> ";
	}
}

void nts::Shell::execLine(const std::string &word)
{
	std::vector<std::unique_ptr<IComponent>> &components = _parser.getComponents();

	if (word == "simulate") {
		_parser.setInputsState(components);
		nts::Exec::compute(components);
	} else if (word == "display") {
		nts::Exec::display(components);
	} else {
		setInput(word);
	}
}

void nts::Shell::setInput(const std::string &word)
{
	try {
		std::pair<std::string, size_t> namePin = nts::KeyValue::create(word, "=");

		_parser.findInputValue(namePin.first);
		_parser.setInputValue(namePin.first, namePin.second);
	} catch (...) {
		std::cout << word + ": command not found" << std::endl;
	}
}
