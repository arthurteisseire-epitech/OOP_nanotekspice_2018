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

int nts::Shell::exec()
{
	std::string word;
	std::vector<std::unique_ptr<IComponent>> &components = _parser.getComponents();

	std::cout << "> ";
	while (getline(std::cin, word) && word != "exit") {
		if (word == "simulate") {
			_parser.setInputsState(components);
			nts::Exec::compute(components);
		} else if (word == "display") {
			nts::Exec::display(components);
		} else {
			try {
				std::pair<std::string, size_t> namePin = KeyValue::create(word, "=");
				_parser.findInputValue(namePin.first);
				_parser.setInputValue(namePin.first, namePin.second);
			} catch (...) {
				std::cout << word + ": command not found" << std::endl;
			}
		}
		std::cout << "> ";
	}
	return 0;
}
