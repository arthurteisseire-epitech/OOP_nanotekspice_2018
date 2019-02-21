/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Component7Seg.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENT7SEG_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENT7SEG_HPP

#include "AComponent.hpp"
#include "IPin.hpp"
#include "ComponentOutput.hpp"

namespace nts {
	class Component7Seg : public ComponentOutput {
	public:
		explicit Component7Seg(const std::string &name);

		Tristate compute(size_t pin) override;
		Tristate localCompute() override;
		void dump() override;
	};
}

#endif