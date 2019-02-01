/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice_2018
** File description:
** Created by Adrien FABRE,
*/

#include <gtest/gtest.h>
#include <iostream>
#include "ComponentAnd.hpp"
#include "ComponentInput.hpp"
#include "ComponentOutput.hpp"

TEST(Compute, SimpleIO)
{
	nts::ComponentInput in("in");
	nts::ComponentOutput out("out");

	out.setLink(0, in, 0);
	out.compute(0);
	EXPECT_EQ(out.getPin(0)->getState(), nts::UNDEFINED);
	in.getPin(0)->setState(nts::TRUE);
	out.compute(0);
	EXPECT_EQ(out.getPin(0)->getState(), nts::TRUE);
}

TEST(Compute, TwoInOneAndOneOut)
{
	nts::ComponentInput in("in");
	nts::ComponentInput in2("in2");
	nts::ComponentOutput out("out");
	nts::ComponentAnd andComp("and");

	out.setLink(0, andComp, 2);
	andComp.setLink(0, in, 0);
	andComp.setLink(1, in2, 0);

	in.getPin(0)->setState(nts::TRUE);
	in2.getPin(0)->setState(nts::TRUE);
	out.compute(0);
	EXPECT_EQ(out.getPin(0)->getState(), nts::TRUE);
}