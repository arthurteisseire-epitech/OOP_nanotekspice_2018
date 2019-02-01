/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** testsParser.cpp
*/

#include <gtest/gtest.h>
#include "Parser.hpp"

TEST(Parser, openFile)
{
	EXPECT_ANY_THROW(nts::Parser parser("file_that_doenst_exist.nts"));
}
