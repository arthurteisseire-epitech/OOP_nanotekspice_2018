/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** AComponent.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENT_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENT_HPP

#include <vector>
#include <bits/unique_ptr.h>
#include "IComponent.hpp"

namespace nts {
	class AComponent : public IComponent {
	public:
		explicit AComponent(const std::vector<Pin> &pins);

		nts::Tristate compute(size_t pin) override;
		void setLink(size_t pin, nts::IComponent &other, size_t otherPin) override;
		void display() override;
		std::unique_ptr<Pin> operator[](size_t pin) const override;
	protected:
		std::vector<std::unique_ptr<Pin>> _pins;
	};
}

#endif
