/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentTrue.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENTTRUE_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENTTRUE_HPP

#include "AComponent.hpp"

namespace nts {
	class ComponentTrue : public AComponent {
	public:
		explicit ComponentTrue(const std::string &name);

		nts::Tristate localCompute() override;
		void dump() override;
	};
}

#endif
