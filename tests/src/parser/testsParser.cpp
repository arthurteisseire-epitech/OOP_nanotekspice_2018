/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** testsParser.cpp
*/

#include <gtest/gtest.h>
#include "Parser.hpp"

static const std::string dir = "../samples/";

TEST(Parser, wrongFile)
{
	EXPECT_ANY_THROW(nts::Parser parser("wrong_file.nts"));
}

TEST(Parser, noChipsets)
{
	EXPECT_ANY_THROW(nts::Parser parser(dir + "no_chipsets.nts"));
}

TEST(Parser, noLinks)
{
	EXPECT_ANY_THROW(nts::Parser parser(dir + "no_links.nts"));
}