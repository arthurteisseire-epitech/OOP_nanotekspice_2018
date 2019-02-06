/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice_2018
** File description:
** Created by Adrien FABRE,
*/

#include <parser/ParserException.hpp>
#include <component/Exec.hpp>
#include "FileParser.hpp"
#include "gtest/gtest.h"

TEST(ComponentOutput, NoLink)
{
	nts::FileParser fileParser(PROJECT_PATH"samples/noLinkAnd.nts");

	EXPECT_ANY_THROW(nts::Exec::compute(fileParser.getComponents()));
}