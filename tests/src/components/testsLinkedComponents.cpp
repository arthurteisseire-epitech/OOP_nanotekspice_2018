/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice_2018
** File description:
** Created by Adrien FABRE,
*/

#include "gtest/gtest.h"
#include "ComponentOutput.hpp"
#include "ComponentInput.hpp"
#include "ComponentAnd.hpp"

TEST(LinkedComponents, ChangeBeforeLink)
{
	nts::ComponentInput in("in");
	nts::ComponentOutput out("out");

	in.getPin(0)->setState(nts::TRUE);
	EXPECT_EQ(out.getPin(0)->getState(), nts::UNDEFINED);
	out.setLink(0, in, 0);
	EXPECT_EQ(out.getPin(0)->getState(), nts::TRUE);
}

TEST(LinkedComponents, ChangeAfterLink)
{
	nts::ComponentInput in("in");
	nts::ComponentOutput out("out");

	EXPECT_EQ(out.getPin(0)->getState(), nts::UNDEFINED);
	out.setLink(0, in, 0);
	in.getPin(0)->setState(nts::TRUE);
	EXPECT_EQ(out.getPin(0)->getState(), nts::TRUE);
}

TEST(LinkedComponents, TwoInputsOneAndOneOutput)
{
	nts::ComponentAnd andComp("and1");
	nts::ComponentOutput out("out");
	nts::ComponentInput in("in");
	nts::ComponentInput in2("in2");

	andComp.setLink(0, in, 0);
	andComp.setLink(1, in2, 0);
	andComp.setLink(2, out, 0);

	in.getPin(0)->setState(nts::TRUE);
	in2.getPin(0)->setState(nts::TRUE);
	out.getPin(0)->setState(nts::TRUE);

	EXPECT_EQ(andComp.getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(andComp.getPin(1)->getState(), nts::TRUE);
	EXPECT_EQ(andComp.getPin(2)->getState(), nts::TRUE);
	EXPECT_EQ(in.getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(in2.getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(out.getPin(0)->getState(), nts::TRUE);
}

TEST(LinkedComponents, OneInputOneAndOneOutput)
{
	nts::ComponentAnd andComp("and1");
	nts::ComponentOutput out("out");
	nts::ComponentInput in("in2");

	andComp.setLink(0, in, 0);
	andComp.setLink(1, in, 0);
	andComp.setLink(2, out, 0);
	in.getPin(0)->setState(nts::TRUE);
	out.getPin(0)->setState(nts::TRUE);
	EXPECT_EQ(andComp.getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(andComp.getPin(1)->getState(), nts::TRUE);
	EXPECT_EQ(andComp.getPin(2)->getState(), nts::TRUE);
}

TEST(LinkedComponents, twoInputsThreeAndOneOutput)
{
	nts::ComponentInput in("in2");
	nts::ComponentInput in2("in2");
	nts::ComponentAnd andComp("and1");
	nts::ComponentAnd andComp2("and2");
	nts::ComponentAnd andFinal("and3");
	nts::ComponentOutput out("out");

	andComp.setLink(0, in, 0);
	andComp.setLink(1, in2, 0);

	andComp2.setLink(0, in, 0);
	andComp2.setLink(1, andComp, 2);

	andFinal.setLink(0, andComp, 2);
	andFinal.setLink(1, andComp2, 2);

	out.setLink(0, andFinal, 2);

	in.getPin(0)->setState(nts::TRUE);
	in2.getPin(0)->setState(nts::FALSE);

	out.compute(0);

	EXPECT_EQ(andComp.getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(andComp.getPin(1)->getState(), nts::FALSE);
	EXPECT_EQ(andComp2.getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(andComp2.getPin(1)->getState(), nts::FALSE);
	EXPECT_EQ(andFinal.getPin(0)->getState(), nts::FALSE);
	EXPECT_EQ(andFinal.getPin(1)->getState(), nts::FALSE);
	EXPECT_EQ(out.getPin(0)->getState(), nts::FALSE);
}