/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** PinValue.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_PINVALUE_HPP
#define OOP_NANOTEKSPICE_2018_PINVALUE_HPP

#include <string>

namespace nts {
	class PinValue {
	public:
		static std::pair<size_t, std::string>
		create(const std::string &link, const std::string &sep);
	private:
		static std::string findValue(const std::string &link, const std::string &sep);
		static size_t findPin(const std::string &link, const std::string &sep);
		static size_t findSepPos(const std::string &link, const std::string &sep);
	};
}

#endif
