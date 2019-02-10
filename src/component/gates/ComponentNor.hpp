/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentAnd.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENTNOR_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENTNOR_HPP

#include "AComponent.hpp"
#include "IPin.hpp"

namespace nts {
	class ComponentNor : public AComponent {
	public:
		explicit ComponentNor(const std::string &name);

		Tristate localCompute() override;
		void dump() override;
	};
}

#endif