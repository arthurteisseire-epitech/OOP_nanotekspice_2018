/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** FileParser.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_FILEPARSER_HPP
#define OOP_NANOTEKSPICE_2018_FILEPARSER_HPP

#include <fstream>
#include "IComponent.hpp"
#include "ComponentFactory.hpp"

namespace nts {
	class FileParser {
	public:
		explicit FileParser(const std::string &filename);
		const std::vector<std::unique_ptr<IComponent>> &getComponents() const;
	private:
		std::vector<std::unique_ptr<IComponent>> _components;
		std::ifstream _file;

		void parseFile();
		void goToSection(const std::string &section);
		void initChipsets();
		const std::string nextType();

		void linkChipsets();
		void linkComponents(const std::pair<std::string, size_t> &pinValue,
		                    const std::pair<std::string, size_t> &otherPinValue) const;
		void linkPins(const std::pair<std::string, size_t> &pinValue,
		              const std::pair<std::string, size_t> &otherPinValue,
		              const std::unique_ptr<nts::IComponent> &component) const;
		bool setPairs(std::pair<std::string, size_t> &pinValue,
		              std::pair<std::string, size_t> &otherPinValue);
	};
}

#endif
