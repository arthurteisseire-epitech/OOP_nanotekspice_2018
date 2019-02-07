/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentAnd.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENTXOR_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENTXOR_HPP

#include "AComponent.hpp"
#include "IPin.hpp"

namespace nts {
	class ComponentXor : public AComponent {
	public:
		explicit ComponentXor(const std::string &name);

		Tristate localCompute() override;
		void dump() override;
	};
}

#endif