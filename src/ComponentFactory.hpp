/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentFactory.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_ACOMPONENTFACTORY_HPP
#define OOP_NANOTEKSPICE_2018_ACOMPONENTFACTORY_HPP

#include <map>
#include <functional>
#include "IComponent.hpp"

namespace nts {
	class ComponentFactory {
	public:
		std::unique_ptr<IComponent> createComponent(const std::string &type,
		                                            const std::string &value);
	private:
		typedef std::function<std::unique_ptr<IComponent>(const std::string &)> createFP;
		typedef std::map<std::string, createFP> ComponentTypes;
		static ComponentTypes _componentTypes;
	};
}

#endif
