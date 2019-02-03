/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Parser.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_PARSER_HPP
#define OOP_NANOTEKSPICE_2018_PARSER_HPP

#include <memory>
#include "ArgParser.hpp"
#include "FileParser.hpp"

namespace nts {
	class Parser {
	public:
		Parser(int ac, const char *av[]);

		void setInputsState(std::vector<std::unique_ptr<nts::IComponent>> &components);
		std::vector<std::unique_ptr<IComponent>> &getComponents();
		size_t findInputValue(const std::string &key) const;
		void setInputValue(const std::string &key, size_t value);
		bool isInputKey(const std::string &key) const;
	private:
		ArgParser _argParser;
		FileParser _fileParser;
	};
}

#endif
