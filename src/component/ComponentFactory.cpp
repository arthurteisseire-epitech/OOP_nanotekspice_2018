/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentFactory.cpp
*/

#include "ParserException.hpp"
#include "ComponentFactory.hpp"
#include "ComponentInput.hpp"
#include "ComponentOutput.hpp"
#include "ComponentAnd.hpp"
#include "ComponentTrue.hpp"

nts::ComponentFactory::ComponentTypes nts::ComponentFactory::_componentTypes = {
	{"input", [](const std::string &value) { return std::make_unique<nts::ComponentInput>(value); }},
	{"output", [](const std::string &value) { return std::make_unique<nts::ComponentOutput>(value); }},
	{"true", [](const std::string &value) { return std::make_unique<nts::ComponentTrue>(value); }},
	{"and", [](const std::string &value) { return std::make_unique<nts::ComponentAnd>(value); }},
};

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createComponent(const std::string &type,
                                                                        const std::string &value)
{
	if (_componentTypes.find(type) == _componentTypes.end())
		throw ParserException("Component '" + type + "' doesn't exists");
	return _componentTypes[type](value);
}
