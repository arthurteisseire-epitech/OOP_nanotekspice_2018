/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** main.cpp
*/

#include "Shell.hpp"
#include "Parser.hpp"
#include "Exec.hpp"

int main(int ac, const char *av[])
{
	nts::Parser parser(ac, av);
	nts::Shell shell(parser);
	std::vector<std::unique_ptr<nts::IComponent>> &components = parser.getComponents();

	nts::Exec::compute(components);
	nts::Exec::display(components);
	return shell.exec();
}