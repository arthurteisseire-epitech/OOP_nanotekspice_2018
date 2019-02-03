/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** NamePin.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_PINVALUE_HPP
#define OOP_NANOTEKSPICE_2018_PINVALUE_HPP

#include <string>

namespace nts {
	class NamePin {
	public:
		static std::pair<std::string, size_t> create(const std::string &link,
		                                             const std::string &sep);
	private:
		static std::string findName(const std::string &link, const std::string &sep);
		static size_t findPin(const std::string &link, const std::string &sep);
		static size_t findSepPos(const std::string &link, const std::string &sep);
	};
}

#endif
