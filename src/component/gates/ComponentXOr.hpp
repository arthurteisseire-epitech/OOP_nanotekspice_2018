/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentXOr.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENTX_OR_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENTX_OR_HPP

#include "AComponent.hpp"
#include "IPin.hpp"

namespace nts {
	class ComponentXOr : public AComponent {
	public:
		explicit ComponentXOr(const std::string &name, int input_nb);

		Tristate localCompute() override;
		void dump() override;
	private:
		int _inputNb;
	};
}

#endif