/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** testsParser.cpp
*/

#include <gtest/gtest.h>
#include "Parser.hpp"
#include "ParserException.hpp"

static const std::string dir = "../samples/";

TEST(Parser, wrongFile)
{
	EXPECT_THROW(nts::Parser parser("wrong_file.nts"), std::ifstream::failure);
}

TEST(Parser, noChipsets)
{
	EXPECT_THROW(nts::Parser parser(dir + "no_chipsets.nts"), nts::ParserException);
}

TEST(Parser, noLinks)
{
	EXPECT_THROW(nts::Parser parser(dir + "no_links.nts"), nts::ParserException);
}