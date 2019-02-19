/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** testsComponentAdder.cpp
*/

#include "Utils.hpp"
#include "Parser.hpp"
#include "Exec.hpp"
#include "FileParser.hpp"
#include "ComponentInput.hpp"
#include "ComponentOutput.hpp"
#include "ComponentAnd.hpp"
#include "ComponentAdder.hpp"

TEST(ComponentAdder, Init)
{
	nts::ComponentAdder componentAdder("Adder");

	Utils::testInitComp(componentAdder, 3, 2);

	EXPECT_EQ(componentAdder.getComponents()[0]->getName(), "halfAdder");
	Utils::testInitComp(*componentAdder.getComponents()[0], 2, 2);
	EXPECT_EQ(componentAdder.getComponents()[1]->getName(), "halfAdder1");
	Utils::testInitComp(*componentAdder.getComponents()[1], 2, 2);

	EXPECT_EQ(componentAdder.getComponents()[2]->getName(), "or");
	Utils::testInitComp(*componentAdder.getComponents()[2], 2, 1);
}

static void testCompute(nts::Tristate inputState, nts::Tristate inputState2, nts::Tristate cInState,
			nts::Tristate expectedOut,
			nts::Tristate expectedCOut)
{
	nts::ComponentAdder componentAdder("Adder");
	nts::ComponentInput input("in");
	nts::ComponentInput input2("in2");
	nts::ComponentInput cin("cin");
	nts::ComponentOutput output("out");
	nts::ComponentOutput cout("cout");

	componentAdder.setLink(0, input, 0);
	componentAdder.setLink(1, input2, 0);
	componentAdder.setLink(2, cin, 0);
	componentAdder.setLink(3, output, 0);
	componentAdder.setLink(4, cout, 0);

	input.getPin(0)->setState(inputState);
	input2.getPin(0)->setState(inputState2);
	cin.getPin(0)->setState(cInState);

	ASSERT_EQ(componentAdder.getPin(0)->getState(), inputState);
	ASSERT_EQ(componentAdder.getPin(1)->getState(), inputState2);
	ASSERT_EQ(componentAdder.getPin(2)->getState(), cInState);

	output.compute(0);
	cout.compute(0);
	EXPECT_EQ(output.getPin(0)->getState(), expectedOut);
	EXPECT_EQ(cout.getPin(0)->getState(), expectedCOut);
}

TEST(ComponentAdder, Compute)
{
	testCompute(nts::TRUE, nts::FALSE, nts::FALSE, nts::TRUE, nts::FALSE);
	testCompute(nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE);
	testCompute(nts::FALSE, nts::FALSE, nts::TRUE, nts::TRUE, nts::FALSE);
	testCompute(nts::TRUE, nts::FALSE, nts::TRUE, nts::FALSE, nts::TRUE);
	testCompute(nts::TRUE, nts::TRUE, nts::TRUE, nts::TRUE, nts::TRUE);
}

TEST(ComponentAdder, Parsing)
{
	const char *av[] = {"b", PROJECT_PATH"samples/simple_components/half_adder.nts", "a=1", "b=1"};
	nts::Parser parser(4, av);

	nts::Exec::compute(parser.getComponents());
	EXPECT_EQ(parser.getComponents()[2]->getPin(0)->getState(), nts::FALSE);
	EXPECT_EQ(parser.getComponents()[3]->getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(parser.getComponents()[4]->getPin(2)->getState(), nts::FALSE);
	EXPECT_EQ(parser.getComponents()[4]->getPin(3)->getState(), nts::TRUE);
}