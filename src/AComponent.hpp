/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** AComponent.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENT_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENT_HPP

#include <vector>
#include <memory>
#include "IComponent.hpp"

namespace nts {
	class AComponent : public IComponent {
	public:
		explicit AComponent(const std::string &name);

		nts::Tristate compute(size_t pin) override = 0;
		void setLink(size_t pin, nts::IComponent &other, size_t otherPin) override;
		void dump() override = 0;
		std::shared_ptr<Pin> operator[](size_t pin) const override;
	protected:
		std::vector<std::shared_ptr<Pin>> _pins;
		const std::string _name;
	};
}

#endif
