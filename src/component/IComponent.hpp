/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** IComponent.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_ICOMPONENT_HPP
#define OOP_NANOTEKSPICE_2018_ICOMPONENT_HPP

#include <vector>
#include "IPin.hpp"

namespace nts {
	class IComponent {
	public:
		virtual ~IComponent() = default;

		virtual nts::Tristate compute(size_t pin) = 0;
		virtual nts::Tristate localCompute() = 0;
		virtual void setLink(size_t pin, nts::IComponent &other, size_t otherPin) = 0;
		virtual void dump() = 0;
		virtual const std::shared_ptr<IPin> getPin(size_t pin) const = 0;
		virtual void setPin(size_t pin, const std::shared_ptr<IPin> &pinPtr) = 0;
		virtual const std::vector<std::shared_ptr<IPin>> &getPins() const = 0;
		virtual const std::string &getName() const = 0;
		virtual const std::string &getType() const = 0;
	};
}

#endif
