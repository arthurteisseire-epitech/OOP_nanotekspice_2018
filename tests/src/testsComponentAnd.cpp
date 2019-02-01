/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice_2018
** File description:
** Created by Adrien FABRE,
*/

#include <gtest/gtest.h>
#include "ComponentAnd.hpp"

TEST(ComponentAnd, init)
{
	nts::ComponentAnd andComp("and");

	EXPECT_EQ(andComp.getPin(0)->getType(), nts::IPin::INPUT);
	EXPECT_EQ(andComp.getPin(0)->getState(), nts::UNDEFINED);

	EXPECT_EQ(andComp.getPin(1)->getType(), nts::IPin::INPUT);
    EXPECT_EQ(andComp.getPin(1)->getState(), nts::UNDEFINED);

    EXPECT_EQ(andComp.getPin(2)->getType(), nts::IPin::OUTPUT);
    EXPECT_EQ(andComp.getPin(2)->getState(), nts::UNDEFINED);
}

TEST(ComponentAnd, TrueAndTrue)
{
    nts::ComponentAnd andComp("and");

    andComp.getPin(0)->setState(nts::TRUE);
    andComp.getPin(1)->setState(nts::TRUE);
    andComp.local_compute();
    EXPECT_EQ(andComp.getPin(0)->getState(), nts::TRUE);
    EXPECT_EQ(andComp.getPin(1)->getState(), nts::TRUE);
    EXPECT_EQ(andComp.getPin(2)->getState(), nts::TRUE);
}

TEST(ComponentAnd, TrueAndFalse)
{
    nts::ComponentAnd andComp("and");

    andComp.getPin(0)->setState(nts::TRUE);
    andComp.getPin(1)->setState(nts::FALSE);
    andComp.local_compute();
    EXPECT_EQ(andComp.getPin(0)->getState(), nts::TRUE);
    EXPECT_EQ(andComp.getPin(1)->getState(), nts::FALSE);
    EXPECT_EQ(andComp.getPin(2)->getState(), nts::FALSE);
}

TEST(ComponentAnd, FalseAndTrue)
{
    nts::ComponentAnd andComp("and");

    andComp.getPin(1)->setState(nts::TRUE);
    andComp.getPin(0)->setState(nts::FALSE);
    andComp.local_compute();
    EXPECT_EQ(andComp.getPin(1)->getState(), nts::TRUE);
    EXPECT_EQ(andComp.getPin(0)->getState(), nts::FALSE);
    EXPECT_EQ(andComp.getPin(2)->getState(), nts::FALSE);
}

TEST(ComponentAnd, FalseAndFalse)
{
    nts::ComponentAnd andComp("and");

    andComp.getPin(0)->setState(nts::FALSE);
    andComp.getPin(1)->setState(nts::FALSE);
    andComp.local_compute();
    EXPECT_EQ(andComp.getPin(0)->getState(), nts::FALSE);
    EXPECT_EQ(andComp.getPin(1)->getState(), nts::FALSE);
    EXPECT_EQ(andComp.getPin(2)->getState(), nts::FALSE);
}

TEST(ComponentAnd, TrueAndUndefined)
{
    nts::ComponentAnd andComp("and");

    andComp.getPin(0)->setState(nts::TRUE);
    andComp.getPin(1)->setState(nts::UNDEFINED);
    andComp.local_compute();
    EXPECT_EQ(andComp.getPin(0)->getState(), nts::TRUE);
    EXPECT_EQ(andComp.getPin(1)->getState(), nts::UNDEFINED);
    EXPECT_EQ(andComp.getPin(2)->getState(), nts::UNDEFINED);
}

TEST(ComponentAnd, FalseAndUndefined)
{
    nts::ComponentAnd andComp("and");

    andComp.getPin(0)->setState(nts::FALSE);
    andComp.getPin(1)->setState(nts::UNDEFINED);
    andComp.local_compute();
    EXPECT_EQ(andComp.getPin(0)->getState(), nts::FALSE);
    EXPECT_EQ(andComp.getPin(1)->getState(), nts::UNDEFINED);
    EXPECT_EQ(andComp.getPin(2)->getState(), nts::FALSE);
}

TEST(ComponentAnd, UndefinedAndUndefined)
{
    nts::ComponentAnd andComp("and");

    andComp.getPin(0)->setState(nts::UNDEFINED);
    andComp.getPin(1)->setState(nts::UNDEFINED);
    andComp.local_compute();
    EXPECT_EQ(andComp.getPin(0)->getState(), nts::UNDEFINED);
    EXPECT_EQ(andComp.getPin(1)->getState(), nts::UNDEFINED);
    EXPECT_EQ(andComp.getPin(2)->getState(), nts::UNDEFINED);
}