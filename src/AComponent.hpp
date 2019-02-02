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
#include "IPin.hpp"
#include "PinInput.hpp"
#include "PinOutput.hpp"
#include "IComponent.hpp"

namespace nts {
	class AComponent : public IComponent {
	public:
		explicit AComponent(const std::string &name);

		nts::Tristate compute(size_t pin) override;
		nts::Tristate localCompute() override = 0;
		void setLink(size_t pin, nts::IComponent &other, size_t otherPin) override;
		void dump() override = 0;
		const std::shared_ptr<IPin> getPin(size_t pin) const override;
		const std::vector<std::shared_ptr<IPin>> &getPins() const override;
		const std::string &getName() const override;
	protected:
		std::vector<std::shared_ptr<IPin>> _pins;
		const std::string _name;
		std::shared_ptr<PinInput> chooseInputPin(
			const std::shared_ptr<IPin> &pin1, const std::shared_ptr<IPin> &pin2);
		std::shared_ptr<PinOutput> chooseOutputPin(
			const std::shared_ptr<IPin> &pin1, const std::shared_ptr<IPin> &pin2);
	};
}

#endif
