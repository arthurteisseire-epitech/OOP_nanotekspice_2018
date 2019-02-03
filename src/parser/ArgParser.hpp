/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ArgParser.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_ARGPARSER_HPP
#define OOP_NANOTEKSPICE_2018_ARGPARSER_HPP

#include <string>
#include<map>
#include "Tristate.hpp"

namespace nts {
	class ArgParser {
	public:
		ArgParser(int ac, const char **av);
		const std::string &getFilename() const;
		size_t findInputValue(const std::string &key) const;
		void setInputValue(const std::string &key, size_t value);
		bool isInputKey(const std::string &key) const;
	private:
		std::string _filename;
		std::map<std::string, size_t> _inputs;
	};
}

#endif
