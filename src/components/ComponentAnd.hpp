/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentAnd.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENTAND_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENTAND_HPP

#include "AComponent.hpp"
#include "IPin.hpp"

namespace nts {
	class ComponentAnd : public AComponent {
	public:
		explicit ComponentAnd(const std::string &name);

		Tristate local_compute() override;
		void dump() override;
	};
}

#endif