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

	nts::Exec::compute(parser.getComponents());
	nts::Exec::display(parser.getComponents());
	return shell.exec();
}