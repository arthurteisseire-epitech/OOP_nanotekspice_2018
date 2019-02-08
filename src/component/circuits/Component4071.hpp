/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Component4071.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENT4071_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENT4071_HPP

#include "ComponentNGates.hpp"
#include "ComponentOr.hpp"

namespace nts {
	class Component4071 : public ComponentNGates<ComponentOr> {
	public:
		explicit Component4071(const std::string &name);
	};
}

#endif
