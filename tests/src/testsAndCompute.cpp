/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice_2018
** File description:
** Created by Adrien FABRE,
*/

#include <gtest/gtest.h>
#include "ComponentInput.hpp"
#include "ComponentOutput.hpp"
#include "ComponentAnd.hpp"

static void testAndCompute(nts::Tristate in1State, nts::Tristate in2State,
                           nts::Tristate expectedOutputState)
{
	nts::ComponentInput in("in");
	nts::ComponentInput in2("in2");
	nts::ComponentOutput out("out");
	nts::ComponentAnd andComp("and");

	out.setLink(0, andComp, 2);
	andComp.setLink(0, in, 0);
	andComp.setLink(1, in2, 0);

	in.getPin(0)->setState(in1State);
	in2.getPin(0)->setState(in2State);
	out.compute(0);
	EXPECT_EQ(out.getPin(0)->getState(), expectedOutputState);
}

TEST(AndCompute, assertions)
{
	testAndCompute(nts::TRUE, nts::TRUE, nts::TRUE);
	testAndCompute(nts::TRUE, nts::FALSE, nts::FALSE);
	testAndCompute(nts::FALSE, nts::TRUE, nts::FALSE);
	testAndCompute(nts::FALSE, nts::FALSE, nts::FALSE);
	testAndCompute(nts::TRUE, nts::UNDEFINED, nts::UNDEFINED);
	testAndCompute(nts::UNDEFINED, nts::TRUE, nts::UNDEFINED);
	testAndCompute(nts::FALSE, nts::UNDEFINED, nts::FALSE);
	testAndCompute(nts::UNDEFINED, nts::FALSE, nts::FALSE);
	testAndCompute(nts::UNDEFINED, nts::UNDEFINED, nts::UNDEFINED);
}