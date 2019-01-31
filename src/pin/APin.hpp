/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** APin.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_APIN_HPP
#define OOP_NANOTEKSPICE_2018_APIN_HPP

#include "IPin.hpp"

namespace nts {
	class APin : public IPin {
	public:
		explicit APin(Type type);
		Type getType() const override;
		Tristate getState() const override;
		void setState(Tristate state) override;
		Tristate compute() override = 0;
	private:
		Type _type;
		Tristate _state;
	};
}

#endif