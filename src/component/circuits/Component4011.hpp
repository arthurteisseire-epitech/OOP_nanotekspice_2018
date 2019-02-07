/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Component4011.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENT4011_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENT4011_HPP

#include "Component4gates.hpp"
#include "ComponentNand.hpp"

namespace nts {
	class Component4011 : public Component4gates<ComponentNand> {
	public:
		explicit Component4011(const std::string &name);
	};
}

#endif
