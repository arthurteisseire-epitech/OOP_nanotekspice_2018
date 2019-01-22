/*
** EPITECH PROJECT, 2018
** cpp_d06_2018
** File description:
** IComponent.hpp
*/

#ifndef CPP_D06_2018_ICOMPONENT_HPP
#define CPP_D06_2018_ICOMPONENT_HPP

namespace nts
{
enum Tristate {
	UNDEFINED = (-true), TRUE = true, FALSE = false
};

class IComponent {
public:
	virtual ~IComponent() = default;

	virtual nts::Tristate compute(std::size_t pin = 1) = 0;
	virtual void setLink(size_t pin, nts::IComponent &other, size_t otherPin) = 0;
	virtual void dump() = 0;
};
}

#endif
