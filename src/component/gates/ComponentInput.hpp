/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentInput.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENTINPUT_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENTINPUT_HPP

#include "AComponent.hpp"

namespace nts {
	class ComponentInput : public AComponent {
	public:
		explicit ComponentInput(const std::string &name);

		Tristate localCompute() override;
		void dump() override;
	};
}

#endif
