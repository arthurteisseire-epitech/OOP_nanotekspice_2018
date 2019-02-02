/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentFactory.cpp
*/

#include "ComponentFactory.hpp"
#include "ComponentInput.hpp"

nts::ComponentFactory::ComponentTypes nts::ComponentFactory::_componentTypes = {
	{"input", [](const std::string &value) { return std::make_unique<nts::ComponentInput>(value); }},
};

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createComponent(const std::string &type,
                                                                         const std::string &value)
{
	return _componentTypes[type](value);
}
