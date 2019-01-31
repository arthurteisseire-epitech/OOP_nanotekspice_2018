/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** IComponent.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_ICOMPONENT_HPP
#define OOP_NANOTEKSPICE_2018_ICOMPONENT_HPP

#include <memory>
#include "Tristate.hpp"
#include "IPin.hpp"

namespace nts {
	class IComponent {
	public:
		virtual ~IComponent() = default;

		virtual nts::Tristate compute(size_t pin = 1) = 0;
		virtual void setLink(size_t pin, nts::IComponent &other, size_t otherPin) = 0;
		virtual void dump() = 0;
	};
}

#endif
