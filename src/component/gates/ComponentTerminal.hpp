/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentTerminal.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENTTERMINAL_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENTTERMINAL_HPP

#include "AComponent.hpp"
#include "IPin.hpp"
#include "ComponentOutput.hpp"

namespace nts {
	class ComponentTerminal : public ComponentOutput {
	public:
		explicit ComponentTerminal(const std::string &name);

		Tristate compute(size_t pin) override;
		Tristate localCompute() override;
		void dump() override;
	};
}

#endif