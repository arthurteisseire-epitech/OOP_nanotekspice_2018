/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** PinOutput.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_PINOUTPUT_HPP
#define OOP_NANOTEKSPICE_2018_PINOUTPUT_HPP

#include "APin.hpp"
#include "IComponent.hpp"

namespace nts {
	class PinOutput : public APin {
	public:
		explicit PinOutput(std::shared_ptr<IComponent> component = nullptr);
		std::shared_ptr<IComponent> getComponent() const;

		Tristate compute() override;
	private:
		std::shared_ptr<IComponent> _component;
	};
}

#endif