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
		explicit PinInput(IComponent &component, PinOutput *linkedOutput = nullptr);

		const std::shared_ptr<PinOutput> getLinkedOutput() const;
		void link(std::shared_ptr<PinOutput> toLink);
		Tristate compute() override;
	private:
		std::shared_ptr<PinOutput> _linkedOutput;
	};
}

#endif
