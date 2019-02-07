/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentNGates.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENTNGATES_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENTNGATES_HPP

#include "ACircuit.hpp"

namespace nts {
	template<typename GateType>
	class ComponentNGates : public ACircuit {
	public:
		explicit ComponentNGates(const std::string &name, size_t gates_nb);
	};
}

#endif