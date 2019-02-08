/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Component4069.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENT4069_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENT4069_HPP

#include "ComponentNGates.hpp"
#include "ComponentNot.hpp"

namespace nts {
	class Component4069 : public ComponentNGates<ComponentNot> {
	public:
		explicit Component4069(const std::string &name);
	};
}

#endif
