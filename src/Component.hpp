/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Component.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENT_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENT_HPP

#include <fstream>

class Component {
public:
	enum state {
		FALSE = false, TRUE = true, UNDIFINED = -1
	};

	Component(int value);
	int exec();
	void link(const Component &other);
private:
	state _state;
	std::ifstream _input;
	std::ofstream _output;
};

#endif
