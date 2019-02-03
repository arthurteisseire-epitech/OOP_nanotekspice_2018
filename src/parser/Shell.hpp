/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Shell.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_SHELL_HPP
#define OOP_NANOTEKSPICE_2018_SHELL_HPP

#include "Parser.hpp"

namespace nts {
	class Shell {
	public:
		explicit Shell(nts::Parser &parser);

		int exec();
	private:
		Parser &_parser;
	};
}

#endif
