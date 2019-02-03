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

		std::vector<std::unique_ptr<IComponent>> &getComponents();
	private:
		ArgParser _argParser;
		FileParser _fileParser;
	};
}

#endif
