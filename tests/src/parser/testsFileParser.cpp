/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** testsParser.cpp
*/

#include "gtest/gtest.h"
#include "IComponent.hpp"
#include "FileParser.hpp"
#include "ParserException.hpp"

static const std::string dir = PROJECT_PATH"samples/";

TEST(FileParser, badFile)
{
	EXPECT_THROW(nts::FileParser("bad_file.nts"), std::ifstream::failure);
}

TEST(FileParser, noChipsetSection)
{
	EXPECT_THROW(nts::FileParser(dir + "no_chipsets.nts"), nts::ParserException);
}

TEST(FileParser, noLinkSection)
{
	EXPECT_THROW(nts::FileParser(dir + "no_links.nts"), nts::ParserException);
}

TEST(FileParser, wrongLinkSeparator)
{
	EXPECT_THROW(nts::FileParser(dir + "wrong_link_sep.nts"), nts::ParserException);
}

TEST(FileParser, createComponents)
{
	nts::FileParser fileParser(dir + "and.nts");
	const std::vector<std::unique_ptr<nts::IComponent>> &components = fileParser.getComponents();

	ASSERT_EQ(components.size(), 4);
	EXPECT_TRUE(components[0]->getName() == "a");
	EXPECT_TRUE(components[1]->getName() == "b");
	EXPECT_TRUE(components[2]->getName() == "s");
	EXPECT_TRUE(components[3]->getName() == "zand");
}

TEST(FileParser, linkComponents)
{
	nts::FileParser fileParser(dir + "and.nts");
	const std::vector<std::unique_ptr<nts::IComponent>> &components = fileParser.getComponents();

	EXPECT_EQ(components[0]->getPin(0), components[3]->getPin(0));
	EXPECT_EQ(components[1]->getPin(0), components[3]->getPin(1));
	EXPECT_EQ(components[2]->getPin(0), components[3]->getPin(2));
}
