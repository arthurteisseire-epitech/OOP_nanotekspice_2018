/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Created by Adrien FABRE,
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENTNOT_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENTNOT_HPP

#include "AComponent.hpp"

namespace nts {
	class ComponentNot : public AComponent {
	public:
		explicit ComponentNot(const std::string &name);

		nts::Tristate localCompute() override;
		void dump() override;
	};
}

#endif //OOP_NANOTEKSPICE_2018_COMPONENTNOT_HPP
