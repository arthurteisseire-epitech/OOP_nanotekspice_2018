/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** PinInput.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_PININPUT_HPP
#define OOP_NANOTEKSPICE_2018_PININPUT_HPP

#include "PinOutput.hpp"

namespace nts {
	class PinInput : public APin {
	public:
		explicit PinInput(std::shared_ptr<PinOutput> linkedOutput = nullptr);

		void setLinkedOutput(std::shared_ptr<PinOutput> toLink);
		std::shared_ptr<PinOutput> getLinkedOutput();
		Tristate compute() override;
	private:
		std::shared_ptr<PinOutput> _linkedOutput;
	};
}

#endif