/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Component4030.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENT4030_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENT4030_HPP

#include "ComponentNGates.hpp"
#include "ComponentXor.hpp"

namespace nts {
	class Component4030 : public ComponentNGates<ComponentXor> {
	public:
		explicit Component4030(const std::string &name);
	};
}

#endif
