/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** testsParser.cpp
*/

#include "gtest/gtest.h"
#include "IComponent.hpp"
#include "parser/Parser.hpp"
#include "parser/ParserException.hpp"

static const std::string dir = "../samples/";

TEST(Parser, badFile)
{
	EXPECT_THROW(nts::Parser parser("bad_file.nts"), std::ifstream::failure);
}

TEST(Parser, noChipsetSection)
{
	EXPECT_THROW(nts::Parser parser(dir + "no_chipsets.nts"), nts::ParserException);
}

TEST(Parser, noLinkSection)
{
	EXPECT_THROW(nts::Parser parser(dir + "no_links.nts"), nts::ParserException);
}

TEST(Parser, wrongLinkSeparator)
{
	EXPECT_THROW(nts::Parser parser(dir + "wrong_link_sep.nts"), nts::ParserException);
}

TEST(Parser, createComponents)
{
	nts::Parser parser(dir + "and.nts");
	const std::vector<std::unique_ptr<nts::IComponent>> &components = parser.getComponents();

	ASSERT_EQ(components.size(), 4);
	EXPECT_TRUE(components[0]->getName() == "a");
	EXPECT_TRUE(components[1]->getName() == "b");
	EXPECT_TRUE(components[2]->getName() == "s");
	EXPECT_TRUE(components[3]->getName() == "gate");
}

TEST(Parser, linkComponents)
{
	nts::Parser parser(dir + "and.nts");
	const std::vector<std::unique_ptr<nts::IComponent>> &components = parser.getComponents();

	EXPECT_EQ(components[0]->getPin(0), components[3]->getPin(0));
	EXPECT_EQ(components[1]->getPin(0), components[3]->getPin(1));
	EXPECT_EQ(components[2]->getPin(0), components[3]->getPin(2));
}
