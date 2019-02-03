/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** testsParser.cpp
*/

#include "gtest/gtest.h"
#include "Parser.hpp"
#include "IComponent.hpp"

TEST(Parser, getComponents)
{
	const char *av[] = {"bin", "../samples/and.nts", "a=1", "b=0"};
	nts::Parser parser(4, av);
	const std::vector<std::unique_ptr<nts::IComponent>> &components = parser.getComponents();

	ASSERT_EQ(components[0]->getPin(0)->getState(), nts::Tristate::TRUE);
	ASSERT_EQ(components[1]->getPin(0)->getState(), nts::Tristate::FALSE);
	ASSERT_EQ(components[2]->getPin(0)->getState(), nts::Tristate::UNDEFINED);
	components[2]->compute(0);
	EXPECT_EQ(components[2]->getPin(0)->getState(), nts::Tristate::FALSE);
}

TEST(Parser, links)
{
	const char *av[] = {"bin", "../samples/and.nts", "a=1", "b=0"};
	nts::Parser parser(4, av);
	const std::vector<std::unique_ptr<nts::IComponent>> &components = parser.getComponents();

	EXPECT_EQ(components[0]->getPin(0), components[3]->getPin(0));
	EXPECT_EQ(components[1]->getPin(0), components[3]->getPin(1));
	EXPECT_EQ(components[2]->getPin(0), components[3]->getPin(2));
}