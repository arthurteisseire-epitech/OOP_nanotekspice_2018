/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** testsArgParser.cpp
*/

#include "gtest/gtest.h"
#include "ArgParser.hpp"
#include "ParserException.hpp"

TEST(ArgParser, noFilename)
{
	const char *array[] = {"bin"};

	EXPECT_THROW(nts::ArgParser(1, array), nts::ParserException);
}

TEST(ArgParser, getFilename)
{
	const char *array[] = {"bin", "filename", "input=0"};
	nts::ArgParser argParser(3, array);

	EXPECT_TRUE(argParser.getFilename() == "filename");
}

TEST(ArgParser, getInput)
{
	const char *array[] = {"bin", "and.nts", "a=0"};
	nts::ArgParser argParser(3, array);

	EXPECT_EQ(argParser.findInputValue("a"), 0);
}