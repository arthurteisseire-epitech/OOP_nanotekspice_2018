/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** testsTrueComponent.cpp
*/

#include "gtest/gtest.h"
#include "Exec.hpp"
#include "FileParser.hpp"

TEST(ComponentTrue, compute)
{
    nts::FileParser fileParser(PROJECT_PATH"samples/basic_components/true.nts");
	nts::Exec::compute(fileParser.getComponents());

	EXPECT_EQ(fileParser.getComponents()[0]->getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(fileParser.getComponents()[1]->getPin(0)->getState(), nts::TRUE);
}