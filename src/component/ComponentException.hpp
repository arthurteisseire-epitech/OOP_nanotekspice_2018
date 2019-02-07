/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentException.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENTEXCEPTION_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENTEXCEPTION_HPP

#include <string>

namespace nts {
	class ComponentException : public std::exception {
	public:
		explicit ComponentException(const std::string &message);

		const char *what() const noexcept override;
	private:
		const std::string _message;
	};
}

#endif
