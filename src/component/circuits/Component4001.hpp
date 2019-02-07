/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Component4001.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENT4001_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENT4001_HPP

#include "ACircuit.hpp"

namespace nts {
	class Component4001 : public ACircuit {
	public:
		explicit Component4001(const std::string &name);

		void dump() override;
	};
}

#endif
