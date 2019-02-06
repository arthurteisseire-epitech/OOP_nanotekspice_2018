/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentTrue.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENTFALSE_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENTFALSE_HPP

#include "AComponent.hpp"

namespace nts {
    class ComponentFalse : public AComponent {
    public:
	explicit ComponentFalse(const std::string &name);

	nts::Tristate localCompute() override;

	void dump() override;
    };
}

#endif
