/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** testsTristate.cpp
*/

#include <criterion/criterion.h>
#include "Tristate.hpp"

Test(Tristate, OR)
{
	nts::Tristate t = nts::TRUE;
	nts::Tristate f = nts::FALSE;
	nts::Tristate u = nts::UNDEFINED;

	cr_expect_eq(t || t, t);
	cr_expect_eq(f || t, t);
	cr_expect_eq(t || f, t);
	cr_expect_eq(f || f, f);

	cr_expect_eq(u || f, u);
	cr_expect_eq(f || u, u);
	cr_expect_eq(t || u, t);
	cr_expect_eq(u || t, t);
	cr_expect_eq(u || u, u);
}

Test(Tristate, AND)
{
	nts::Tristate t = nts::TRUE;
	nts::Tristate f = nts::FALSE;
	nts::Tristate u = nts::UNDEFINED;

	cr_expect_eq(t && t, t);
	cr_expect_eq(f && t, f);
	cr_expect_eq(t && f, f);
	cr_expect_eq(f && f, f);

	cr_expect_eq(u && f, f);
	cr_expect_eq(f && u, f);
	cr_expect_eq(t && u, u);
	cr_expect_eq(u && t, u);
	cr_expect_eq(u && u, u);
}

Test(Tristate, XOR)
{
	nts::Tristate t = nts::TRUE;
	nts::Tristate f = nts::FALSE;
	nts::Tristate u = nts::UNDEFINED;

	cr_expect_eq(t ^ t, f);
	cr_expect_eq(f ^ t, t);
	cr_expect_eq(t ^ f, t);
	cr_expect_eq(f ^ f, f);

	cr_expect_eq(u ^ f, u);
	cr_expect_eq(f ^ u, u);
	cr_expect_eq(t ^ u, u);
	cr_expect_eq(u ^ t, u);
	cr_expect_eq(u ^ u, u);
}