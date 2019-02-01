/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice_2018
** File description:
** Created by Adrien FABRE,
*/

#include <gtest/gtest.h>
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