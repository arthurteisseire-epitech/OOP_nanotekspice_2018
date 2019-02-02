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
		std::vector<std::unique_ptr<IComponent>> _components;
		std::ifstream _file;

		void parseFile();
		void goToSection(const std::string &section);
		void initChipsets();
		void linkChipsets();

		void linkComponents(const std::pair<size_t, std::string> &pinValue,
		                    const std::pair<size_t, std::string> &otherPinValue) const;
		void linkPins(const std::pair<size_t, std::string> &pinValue,
		              const std::pair<size_t, std::string> &otherPinValue,
		              const std::unique_ptr<nts::IComponent> &component) const;
		bool setPairs(std::pair<size_t, std::string> &pinValue,
		              std::pair<size_t, std::string> &otherPinValue);
		std::pair<size_t, std::string> createPair(const std::string &link) const;
		std::string findValue(const std::string &link) const;
		size_t findPin(const std::string &link) const;
		size_t findSepPos(const std::string &link) const;
	};
}

#endif
