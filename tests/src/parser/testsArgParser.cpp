/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** testsArgParser.cpp
*/

#include "gtest/gtest.h"
#include "ArgParser.hpp"

TEST(ArgParser, getFilename)
{
	const char *array[] = {"bin", "filename", "input=0"};
	nts::ArgParser argParser(3, array);

	EXPECT_TRUE(argParser.getFilename() == "filename");
}