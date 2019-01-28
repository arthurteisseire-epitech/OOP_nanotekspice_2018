/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Pin.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_PIN_HPP
#define OOP_NANOTEKSPICE_2018_PIN_HPP

#include <string>
#include "Tristate.hpp"

namespace nts {
	class Pin {
	public:
		Pin(const std::string &name, Tristate input, Tristate output);
	private:
		std::string _name;
		Tristate _input;
		Tristate _output;
	};
}

#endif
