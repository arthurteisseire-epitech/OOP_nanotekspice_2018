/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Component4001.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENT4001_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENT4001_HPP

#include "ComponentNGates.hpp"
#include "ComponentNor.hpp"

namespace nts {
	class Component4001 : public ComponentNGates<ComponentNor> {
	public:
		explicit Component4001(const std::string &name);
	};
}

#endif
