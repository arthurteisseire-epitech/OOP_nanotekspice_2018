/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentHalfAdder.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENTHALFADDER_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENTHALFADDER_HPP

#include "ACircuit.hpp"

namespace nts {
	class ComponentHalfAdder : public ACircuit {
	public:
		explicit ComponentHalfAdder(const std::string &name);
	};
}

#endif