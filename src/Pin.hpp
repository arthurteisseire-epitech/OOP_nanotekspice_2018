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
		enum Type {INPUT, OUTPUT};
		Pin(Tristate state, Type type);

		Tristate getState() const;
		Type getType() const;
	private:
		Tristate _state;
		Type _type;
	};
}

#endif
