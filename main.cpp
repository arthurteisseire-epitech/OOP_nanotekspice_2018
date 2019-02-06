/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** main.cpp
*/

#include <iostream>
#include "Shell.hpp"
#include "Parser.hpp"
#include "Exec.hpp"

int exec(int ac, const char *av[])
{
	nts::Parser parser(ac, av);
	nts::Shell shell(parser);

	nts::Exec::compute(parser.getComponents());
	nts::Exec::display(parser.getComponents());
	return shell.exec();
}

int main(int ac, const char *av[])
{
	try {
		return exec(ac, av);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}