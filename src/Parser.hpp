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

namespace nts {
	class Parser {
	public:
		explicit Parser(const std::string &filename);
	private:
		void handleContentErrors() const;
		std::ifstream _file;
	};
}

#endif
