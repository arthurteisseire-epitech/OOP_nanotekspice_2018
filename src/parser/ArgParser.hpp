/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ArgParser.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_ARGPARSER_HPP
#define OOP_NANOTEKSPICE_2018_ARGPARSER_HPP

#include <string>

namespace nts {
	class ArgParser {
	public:
		ArgParser(int ac, const char **av);
		const std::string &getFilename() const;
	private:
		std::string _filename;
	};
}

#endif
