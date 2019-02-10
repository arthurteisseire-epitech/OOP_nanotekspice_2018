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

static const std::string dir = PROJECT_PATH"samples/invalid_files/";

TEST(FileParser, BadFile)
{
	EXPECT_THROW(nts::FileParser("bad_file.nts"), std::ifstream::failure);
}

TEST(FileParser, NoChipsetSection)
{
	EXPECT_THROW(nts::FileParser(dir + "no_chipsets.nts"), nts::ParserException);
}

TEST(FileParser, NoLinkSection)
{
	EXPECT_THROW(nts::FileParser(dir + "no_links.nts"), nts::ParserException);
}

TEST(FileParser, WrongLinkSeparator)
{
	EXPECT_THROW(nts::FileParser(dir + "wrong_link_sep.nts"), nts::ParserException);
}

TEST(FileParser, PinOutOfRange)
{
	EXPECT_THROW(nts::FileParser(dir + "pin_out_of_range.nts"), nts::ParserException);
}

TEST(FileParser, NegativePin)
{
	EXPECT_THROW(nts::FileParser(dir + "negative_pin.nts"), nts::ParserException);
}

TEST(FileParser, SameComponentNames)
{
	EXPECT_THROW(nts::FileParser(dir + "same_component_names.nts"), nts::ParserException);
}

TEST(FileParser, CreateComponents)
{
	nts::FileParser fileParser(PROJECT_PATH"samples/gates/and.nts");
	const std::vector<std::unique_ptr<nts::IComponent>> &components = fileParser.getComponents();

	ASSERT_EQ(components.size(), (size_t) 4);
	EXPECT_TRUE(components[0]->getName() == "a");
	EXPECT_TRUE(components[1]->getName() == "b");
	EXPECT_TRUE(components[2]->getName() == "s");
	EXPECT_TRUE(components[3]->getName() == "zand");
}

TEST(FileParser, LinkComponents)
{
	nts::FileParser fileParser(PROJECT_PATH"samples/gates/and.nts");
	const std::vector<std::unique_ptr<nts::IComponent>> &components = fileParser.getComponents();

	EXPECT_EQ(components[0]->getPin(0)->getStatePtr(), components[3]->getPin(0)->getStatePtr());
	EXPECT_EQ(components[1]->getPin(0)->getStatePtr(), components[3]->getPin(1)->getStatePtr());
	EXPECT_EQ(components[2]->getPin(0)->getStatePtr(), components[3]->getPin(2)->getStatePtr());
}