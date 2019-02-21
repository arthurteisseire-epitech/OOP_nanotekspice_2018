/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Component4013.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENT4013_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENT4013_HPP

#include "ACircuit.hpp"
#include "IPin.hpp"

namespace nts {
	class Component4013 : public ACircuit {
	public:
		explicit Component4013(const std::string &name);
	};
}

#endif