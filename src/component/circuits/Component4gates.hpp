/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Component4gates.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENT4gates_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENT4gates_HPP

#include "ACircuit.hpp"

namespace nts {
	template<typename GateType>
	class Component4gates : public ACircuit {
	public:
		explicit Component4gates(const std::string &name);
	};
}

#endif