/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** IComponent.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_ICOMPONENT_HPP
#define OOP_NANOTEKSPICE_2018_ICOMPONENT_HPP

#include <cstddef>
#include "Tristate.hpp"
#include "Pin.hpp"

namespace nts {
	class IComponent {
	public:
		virtual ~IComponent() = default;

		virtual nts::Tristate compute(size_t pin) = 0;
		virtual void setLink(size_t pin, nts::IComponent &other, size_t otherPin) = 0;
		virtual void display() = 0;
		virtual std::unique_ptr<Pin> operator[](size_t pin) const = 0;
	};
}

#endif
