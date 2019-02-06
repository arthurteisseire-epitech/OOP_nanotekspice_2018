/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Tristate.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_TRISTATE_HPP
#define OOP_NANOTEKSPICE_2018_TRISTATE_HPP

namespace nts {
	enum Tristate {
		UNDEFINED = (-true),
		TRUE = true,
		FALSE = false
	};

	Tristate operator||(Tristate a, Tristate b);
	Tristate operator&&(Tristate a, Tristate b);
	Tristate operator^(Tristate a, Tristate b);
	Tristate operator!(Tristate a);
}

#endif
