/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** PinInput.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_PININPUT_HPP
#define OOP_NANOTEKSPICE_2018_PININPUT_HPP

#include "IPin.hpp"
#include "PinOutput.hpp"

namespace nts {
	class PinInput : public IPin {
	public:
		explicit PinInput(std::shared_ptr<PinOutput> &linkedOutput);

		Tristate compute() override {}
		Type getType() const;
	private:
		Type _type;
		std::shared_ptr<PinOutput> _linkedOutput;
	};
}

#endif
