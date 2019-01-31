/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** IPin.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_IPIN_HPP
#define OOP_NANOTEKSPICE_2018_IPIN_HPP

#include "Tristate.hpp"

namespace nts {
	class IPin {
	public:
		virtual ~IPin() = default;
		enum Type {INPUT, OUTPUT};

		virtual Tristate compute() = 0;
	};
}

#endif
