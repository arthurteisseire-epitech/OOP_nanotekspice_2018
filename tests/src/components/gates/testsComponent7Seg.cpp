/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice_2018
** File description:
** Created by Adrien FABRE,
*/

#include <Exec.hpp>
#include "gtest/gtest.h"
#include "Parser.hpp"

TEST(Component7Seg, Parsing)
{
	testing::internal::CaptureStdout();
	const char *av[] = {"b", PROJECT_PATH"samples/gates/7seg.nts", "a0=1", "a1=1", "a2=1", "a3=1"};
	nts::Parser parser(6, av);
	std::string output;

	nts::Exec::compute(parser.getComponents());
	EXPECT_EQ(parser.getComponents()[4]->getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(parser.getComponents()[4]->getPin(1)->getState(), nts::TRUE);
	EXPECT_EQ(parser.getComponents()[4]->getPin(2)->getState(), nts::TRUE);
	EXPECT_EQ(parser.getComponents()[4]->getPin(3)->getState(), nts::TRUE);
	output = testing::internal::GetCapturedStdout();
	EXPECT_TRUE(output == "0xf");
}