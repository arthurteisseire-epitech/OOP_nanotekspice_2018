/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentAnd.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENTNAND_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENTNAND_HPP

#include "AComponent.hpp"
#include "IPin.hpp"

namespace nts {
	class ComponentNand : public AComponent {
	public:
		explicit ComponentNand(const std::string &name);

		Tristate localCompute() override;
		void dump() override;
	};
}

#endif