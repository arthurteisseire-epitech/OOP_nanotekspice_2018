/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** testsComponentAdder.cpp
*/

#include "gtest/gtest.h"
#include "Parser.hpp"
#include "Exec.hpp"
#include "FileParser.hpp"
#include "ComponentInput.hpp"
#include "ComponentOutput.hpp"
#include "ComponentAnd.hpp"
//#include "ComponentAdder.hpp"
//
//TEST(ComponentAdder, Init)
//{
//	nts::ComponentAdder componentAdder("Adder");
//
//	EXPECT_EQ(componentAdder.getPin(0), componentAdder.getComponents()[0]->getPin(0));
//	EXPECT_EQ(componentAdder.getPin(1), componentAdder.getComponents()[0]->getPin(1));
//	EXPECT_EQ(componentAdder.getPin(2), componentAdder.getComponents()[0]->getPin(2));
//	EXPECT_EQ(componentAdder.getPin(2), componentAdder.getComponents()[0]->getPin(2));
//	EXPECT_EQ(componentAdder.getPin(2), componentAdder.getComponents()[0]->getPin(2));
//}
//
//TEST(ComponentAdder, NorGate)
//{
//	nts::ComponentAdder componentAdder("Adder");
//
//	componentAdder.getComponents()[0]->getPin(0)->setState(nts::TRUE);
//	componentAdder.getComponents()[0]->getPin(1)->setState(nts::FALSE);
//	componentAdder.getComponents()[0]->localCompute();
//	EXPECT_EQ(componentAdder.getComponents()[0]->getPin(2)->getState(), nts::FALSE);
//}
//
//TEST(ComponentAdder, Compute)
//{
//	nts::ComponentAdder componentAdder("Adder");
//	nts::ComponentInput input("in");
//	nts::ComponentInput input2("in2");
//	nts::ComponentOutput output("out");
//
//	componentAdder.setLink(0, input, 0);
//	componentAdder.setLink(1, input2, 0);
//	componentAdder.setLink(2, output, 0);
//
//	input.getPin(0)->setState(nts::TRUE);
//	input2.getPin(0)->setState(nts::FALSE);
//
//	ASSERT_EQ(componentAdder.getPin(0)->getState(), nts::TRUE);
//	ASSERT_EQ(componentAdder.getPin(1)->getState(), nts::FALSE);
//	ASSERT_EQ(componentAdder.getPin(2)->getState(), nts::UNDEFINED);
//
//	output.compute(0);
//	ASSERT_EQ(componentAdder.getComponents()[0]->getPin(2)->getState(), nts::FALSE);
//	EXPECT_EQ(output.getPin(0)->getState(), nts::FALSE);
//	input.getPin(0)->setState(nts::FALSE);
//	input2.getPin(0)->setState(nts::FALSE);
//	output.compute(0);
//	EXPECT_EQ(output.getPin(0)->getState(), nts::TRUE);
//}
//
//TEST(ComponentAdder, Parsing)
//{
//	const char *av[] = {"b", PROJECT_PATH"samples/simple_components/Adder_nor.nts", "a=1", "b=1"};
//	nts::Parser parser(4, av);
//
//	nts::Exec::compute(parser.getComponents());
//	EXPECT_EQ(parser.getComponents()[2]->getPin(2)->getState(), nts::FALSE);
//	EXPECT_EQ(parser.getComponents()[3]->getPin(0)->getState(), nts::FALSE);
//}