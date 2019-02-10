/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Utils.cpp,
*/

#include "Utils.hpp"

void Utils::testInitComp(const nts::IComponent &comp, int inputNb, int outputNb)
{
	int i;

	for (i = 0; i < inputNb; ++i) {
		EXPECT_EQ(comp.getPin(i)->getType(), nts::IPin::INPUT);
		EXPECT_EQ(comp.getPin(i)->getState(), nts::UNDEFINED);
	}
	for (; i < outputNb; ++i) {
		EXPECT_EQ(comp.getPin(i)->getType(), nts::IPin::OUTPUT);
		EXPECT_EQ(comp.getPin(i)->getState(), nts::UNDEFINED);
	}
}
