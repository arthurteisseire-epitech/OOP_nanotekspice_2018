/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentAdder.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENTADDER_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENTADDER_HPP

#include "ACircuit.hpp"

namespace nts {
	class ComponentAdder : public ACircuit {
	public:
		explicit ComponentAdder(const std::string &name);
	};
}

#endif