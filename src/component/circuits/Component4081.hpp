/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Component4081.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENT4081_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENT4081_HPP

#include "Component4gates.hpp"

namespace nts {
	class Component4081 : public Component4gates<ComponentAnd> {
	public:
		explicit Component4081(const std::string &name);
	};
}

#endif
