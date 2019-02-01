/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ParserException.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_PARSEREXCEPTION_HPP
#define OOP_NANOTEKSPICE_2018_PARSEREXCEPTION_HPP

#include <string>

namespace nts {
	class ParserException : public std::exception {
	public:
		explicit ParserException(const std::string &message);
		const char *what() const noexcept override;
	private:
		const std::string _message;
	};
}

#endif
