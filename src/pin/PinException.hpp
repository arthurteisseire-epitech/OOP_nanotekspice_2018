/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** PinException.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_PINEXCEPTION_HPP
#define OOP_NANOTEKSPICE_2018_PINEXCEPTION_HPP

#include <string>

namespace nts {
	class PinException : public std::exception {
	public:
		explicit PinException(const std::string &message);
		const char *what() const noexcept override;
	private:
		const std::string _message;
	};
}

#endif
