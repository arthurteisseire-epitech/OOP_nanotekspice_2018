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
#include "ComponentTrue.hpp"
#include "ComponentFalse.hpp"
#include "ComponentClock.hpp"
#include "ComponentNot.hpp"
#include "ComponentAnd.hpp"
#include "ComponentNand.hpp"
#include "ComponentOr.hpp"
#include "ComponentNor.hpp"
#include "ComponentXor.hpp"
#include "Component4001.hpp"
#include "Component4011.hpp"
#include "Component4030.hpp"
#include "Component4069.hpp"
#include "Component4071.hpp"
#include "Component4081.hpp"

nts::ComponentFactory::ComponentTypes nts::ComponentFactory::_componentTypes = {
	{"input",  [](const std::string &value) { return std::make_unique<nts::ComponentInput>(value); }},
	{"output", [](const std::string &value) { return std::make_unique<nts::ComponentOutput>(value); }},
	{"true",   [](const std::string &value) { return std::make_unique<nts::ComponentTrue>(value); }},
	{"false",  [](const std::string &value) { return std::make_unique<nts::ComponentFalse>(value); }},
	{"clock",  [](const std::string &value) { return std::make_unique<nts::ComponentClock>(value); }},
	{"not",    [](const std::string &value) { return std::make_unique<nts::ComponentNot>(value); }},
	{"and",    [](const std::string &value) { return std::make_unique<nts::ComponentAnd>(value); }},
	{"nand",   [](const std::string &value) { return std::make_unique<nts::ComponentNand>(value); }},
	{"or",     [](const std::string &value) { return std::make_unique<nts::ComponentOr>(value); }},
	{"nor",    [](const std::string &value) { return std::make_unique<nts::ComponentNor>(value); }},
	{"xor",    [](const std::string &value) { return std::make_unique<nts::ComponentXor>(value); }},
	{"4001",   [](const std::string &value) { return std::make_unique<nts::Component4001>(value); }},
	{"4011",   [](const std::string &value) { return std::make_unique<nts::Component4011>(value); }},
	{"4030",   [](const std::string &value) { return std::make_unique<nts::Component4030>(value); }},
	{"4069",   [](const std::string &value) { return std::make_unique<nts::Component4069>(value); }},
	{"4071",   [](const std::string &value) { return std::make_unique<nts::Component4071>(value); }},
	{"4081",   [](const std::string &value) { return std::make_unique<nts::Component4081>(value); }},
};

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createComponent(const std::string &type,
									const std::string &value)
{
	if (_componentTypes.find(type) == _componentTypes.end())
		throw ParserException("Component '" + type + "' doesn't exists");
	return _componentTypes[type](value);
}
