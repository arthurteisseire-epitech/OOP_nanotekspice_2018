/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** testsParser.cpp
*/

#include <gtest/gtest.h>
#include "Parser.hpp"

TEST(Parser, wrongFile)
{
	EXPECT_ANY_THROW(nts::Parser parser("wrong_file.nts"));
}
