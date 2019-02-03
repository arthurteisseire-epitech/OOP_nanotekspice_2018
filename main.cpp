/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** main.cpp
*/

#include "Parser.hpp"
#include "DisplayOutputs.cpp"

int main(int ac, const char *av[])
{
	nts::Parser parser(ac, av);
	const std::vector<std::unique_ptr<nts::IComponent>> &components = parser.getComponents();

	components[2]->compute(0);
	nts::display(components);
}