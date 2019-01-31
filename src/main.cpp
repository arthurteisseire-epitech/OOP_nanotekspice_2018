/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** main.cpp
*/

#include "ComponentInput.hpp"
#include "ComponentOutput.hpp"

int main()
{
	auto input0(nts::ComponentInput("i0"));
	auto output(nts::ComponentOutput("output"));

	output.setLink(0, input0, 0);
	output.compute(0);
}