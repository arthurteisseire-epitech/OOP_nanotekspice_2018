/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentFlipFlop.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENTFLIPFLOP_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENTFLIPFLOP_HPP

#include "AComponent.hpp"
#include "IPin.hpp"

namespace nts {
	class ComponentFlipFlop : public AComponent {
	public:
		explicit ComponentFlipFlop(const std::string &name);

		Tristate localCompute() override;
		void dump() override;
	private:
		void changeOutputState();
	};
}

#endif