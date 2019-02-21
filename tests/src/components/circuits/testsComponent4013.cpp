/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** testsComponent4013.cpp
*/

#include "gtest/gtest.h"
#include "Parser.hpp"
#include "Exec.hpp"
#include "FileParser.hpp"
#include "ComponentInput.hpp"
#include "ComponentOutput.hpp"
#include "ComponentAnd.hpp"
#include "Component4013.hpp"

TEST(Component4013, Init)
{
	nts::Component4013 component4013("4013");

	EXPECT_EQ(component4013.getPin(0), component4013.getComponents()[0]->getPin(0));
	EXPECT_EQ(component4013.getPin(1), component4013.getComponents()[0]->getPin(1));
	EXPECT_EQ(component4013.getPin(2), component4013.getComponents()[0]->getPin(2));
	EXPECT_EQ(component4013.getPin(3), component4013.getComponents()[0]->getPin(3));
	EXPECT_EQ(component4013.getPin(4), component4013.getComponents()[0]->getPin(4));
	EXPECT_EQ(component4013.getPin(5), component4013.getComponents()[0]->getPin(5));
	EXPECT_EQ(component4013.getPin(6), nullptr);
	EXPECT_EQ(component4013.getPin(7), component4013.getComponents()[1]->getPin(5));
	EXPECT_EQ(component4013.getPin(8), component4013.getComponents()[1]->getPin(4));
	EXPECT_EQ(component4013.getPin(9), component4013.getComponents()[1]->getPin(3));
	EXPECT_EQ(component4013.getPin(10), component4013.getComponents()[1]->getPin(2));
	EXPECT_EQ(component4013.getPin(11), component4013.getComponents()[1]->getPin(1));
	EXPECT_EQ(component4013.getPin(12), component4013.getComponents()[1]->getPin(0));
	EXPECT_EQ(component4013.getPin(13), nullptr);
}

TEST(Component4013, Compute)
{
	nts::Component4013 component4013("4013");
	nts::ComponentInput clockC("clock");
	nts::ComponentInput resetC("reset");
	nts::ComponentInput dataC("data");
	nts::ComponentInput setC("set");
	nts::ComponentOutput out("out");
	nts::ComponentOutput out2("out2");

	out.setLink(0, component4013, 0);
	out2.setLink(0, component4013, 1);
	component4013.setLink(2, clockC, 0);
	component4013.setLink(3, resetC, 0);
	component4013.setLink(4, dataC, 0);
	component4013.setLink(5, setC, 0);

	clockC.getPin(0)->setState(nts::TRUE);
	resetC.getPin(0)->setState(nts::TRUE);
	dataC.getPin(0)->setState(nts::TRUE);
	setC.getPin(0)->setState(nts::TRUE);
	EXPECT_EQ(out2.getPin(0)->getState(), nts::UNDEFINED);
	EXPECT_EQ(out.getPin(0)->getState(), nts::UNDEFINED);
	out.compute(0);
	EXPECT_EQ(out.getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(out2.getPin(0)->getState(), nts::TRUE);
}

TEST(Component4013, Parsing)
{
	const char *av[] = {"b", PROJECT_PATH"samples/simple_components/4013_flip_flop.nts", "aclock=1", "areset=1",
			    "adata=1", "aset=1"};
	nts::Parser parser(6, av);

	nts::Exec::compute(parser.getComponents());
	EXPECT_EQ(parser.getComponents()[4]->getPin(0)->getState(), nts::TRUE);
	EXPECT_EQ(parser.getComponents()[5]->getPin(0)->getState(), nts::TRUE);
}
