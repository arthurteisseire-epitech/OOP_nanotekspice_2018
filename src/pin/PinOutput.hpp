/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** PinOutput.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_PINOUTPUT_HPP
#define OOP_NANOTEKSPICE_2018_PINOUTPUT_HPP

#include "IPin.hpp"

namespace nts {
	class PinOutput : public IPin {
	public:
		PinOutput();

		Tristate compute(IComponent *component) override {}
		Type getType() const;
	private:
		Type _type;
	};
}


#endif
