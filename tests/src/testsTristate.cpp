/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** testsTristate.cpp
*/

#include <gtest/gtest.h>
#include "Tristate.hpp"

TEST(Tristate, OR)
{
	nts::Tristate t = nts::TRUE;
	nts::Tristate f = nts::FALSE;
	nts::Tristate u = nts::UNDEFINED;

	EXPECT_EQ(t || t, t);
	EXPECT_EQ(f || t, t);
	EXPECT_EQ(t || f, t);
	EXPECT_EQ(f || f, f);

	EXPECT_EQ(u || f, u);
	EXPECT_EQ(f || u, u);
	EXPECT_EQ(t || u, t);
	EXPECT_EQ(u || t, t);
	EXPECT_EQ(u || u, u);
}

TEST(Tristate, AND)
{
	nts::Tristate t = nts::TRUE;
	nts::Tristate f = nts::FALSE;
	nts::Tristate u = nts::UNDEFINED;

	EXPECT_EQ(t && t, t);
	EXPECT_EQ(f && t, f);
	EXPECT_EQ(t && f, f);
	EXPECT_EQ(f && f, f);

	EXPECT_EQ(u && f, f);
	EXPECT_EQ(f && u, f);
	EXPECT_EQ(t && u, u);
	EXPECT_EQ(u && t, u);
	EXPECT_EQ(u && u, u);
}

TEST(Tristate, XOR)
{
	nts::Tristate t = nts::TRUE;
	nts::Tristate f = nts::FALSE;
	nts::Tristate u = nts::UNDEFINED;

	EXPECT_EQ(t ^ t, f);
	EXPECT_EQ(f ^ t, t);
	EXPECT_EQ(t ^ f, t);
	EXPECT_EQ(f ^ f, f);

	EXPECT_EQ(u ^ f, u);
	EXPECT_EQ(f ^ u, u);
	EXPECT_EQ(t ^ u, u);
	EXPECT_EQ(u ^ t, u);
	EXPECT_EQ(u ^ u, u);
}