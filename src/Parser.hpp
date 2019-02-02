/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Parser.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_PARSER_HPP
#define OOP_NANOTEKSPICE_2018_PARSER_HPP

#include <string>
#include <fstream>
#include "IComponent.hpp"
#include "ComponentFactory.hpp"

namespace nts {
	class Parser {
	public:
		explicit Parser(const std::string &filename);
		const std::vector<std::unique_ptr<IComponent>> &getComponents() const;
	private:
		void parserFile();
		std::vector<std::unique_ptr<IComponent>> _components;
		std::ifstream _file;
		void goToSection(const std::string &section);
		void initChipsets();
		ComponentFactory _componentFactory;
	};
}

#endif
