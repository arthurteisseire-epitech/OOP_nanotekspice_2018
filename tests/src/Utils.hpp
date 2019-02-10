/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Utils.hpp,
*/

#ifndef OOP_NANOTEKSPICE_2018_UTILS_HPP
#define OOP_NANOTEKSPICE_2018_UTILS_HPP

#include "gtest/gtest.h"
#include "IComponent.hpp"

class Utils {
public:
	static void testInitComp(const nts::IComponent &comp, int inputNb, int outputNb);
};


#endif //OOP_NANOTEKSPICE_2018_UTILS_HPP
