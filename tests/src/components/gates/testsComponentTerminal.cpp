/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice_2018
** File description:
** Created by Adrien FABRE,
*/

#include <Exec.hpp>
#include "gtest/gtest.h"
#include "Parser.hpp"

TEST(ComponentTerminal, Parsing)
{
	testing::internal::CaptureStdout();
	const char *av[] = {"b", PROJECT_PATH"samples/gates/terminal.nts", "a0=0", "a1=1", "a2=0", "a3=0",
			    "a4=0", "a5=0", "a6=0", "a7=1", "print=1"};
	nts::Parser parser(11, av);
	std::string output;

	nts::Exec::compute(parser.getComponents());
	EXPECT_EQ(parser.getComponents()[9]->getPin(0)->getState(), nts::FALSE);
	EXPECT_EQ(parser.getComponents()[9]->getPin(1)->getState(), nts::TRUE);
	EXPECT_EQ(parser.getComponents()[9]->getPin(2)->getState(), nts::FALSE);
	EXPECT_EQ(parser.getComponents()[9]->getPin(3)->getState(), nts::FALSE);
	EXPECT_EQ(parser.getComponents()[9]->getPin(4)->getState(), nts::FALSE);
	EXPECT_EQ(parser.getComponents()[9]->getPin(5)->getState(), nts::FALSE);
	EXPECT_EQ(parser.getComponents()[9]->getPin(6)->getState(), nts::FALSE);
	EXPECT_EQ(parser.getComponents()[9]->getPin(7)->getState(), nts::TRUE);
	EXPECT_EQ(parser.getComponents()[9]->getPin(8)->getState(), nts::TRUE);
	output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output.c_str()[0], 'A');
}