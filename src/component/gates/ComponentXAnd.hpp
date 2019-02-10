/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentXAnd.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENTXAND_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENTXAND_HPP

#include "AComponent.hpp"
#include "IPin.hpp"

namespace nts {
	class ComponentXAnd : public AComponent {
	public:
		ComponentXAnd(const std::string &name, int input_nb);

		Tristate localCompute() override;
		void dump() override;
	private:
		int _inputNb;
	};
}

#endif