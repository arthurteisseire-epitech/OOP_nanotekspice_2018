/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice_2018
** File description:
** Created by Adrien FABRE,
*/

#include <criterion/criterion.h>
#include "ComponentAnd.hpp"

Test(ComponentAnd, init)
{
	nts::ComponentAnd andComp("and");

	cr_expect_eq(andComp.getPin(0)->getType(), nts::IPin::INPUT);
	cr_expect_eq(andComp.getPin(0)->getState(), nts::UNDEFINED);

	cr_expect_eq(andComp.getPin(1)->getType(), nts::IPin::INPUT);
    cr_expect_eq(andComp.getPin(1)->getState(), nts::UNDEFINED);

    cr_expect_eq(andComp.getPin(2)->getType(), nts::IPin::OUTPUT);
    cr_expect_eq(andComp.getPin(2)->getState(), nts::UNDEFINED);
}

Test(ComponentAnd, TrueAndTrue)
{
    nts::ComponentAnd andComp("and");

    andComp.getPin(0)->setState(nts::TRUE);
    andComp.getPin(1)->setState(nts::TRUE);
    andComp.local_compute();
    cr_expect_eq(andComp.getPin(0)->getState(), nts::TRUE);
    cr_expect_eq(andComp.getPin(1)->getState(), nts::TRUE);
    cr_expect_eq(andComp.getPin(2)->getState(), nts::TRUE);
}

Test(ComponentAnd, TrueAndFalse)
{
    nts::ComponentAnd andComp("and");

    andComp.getPin(0)->setState(nts::TRUE);
    andComp.getPin(1)->setState(nts::FALSE);
    andComp.local_compute();
    cr_expect_eq(andComp.getPin(0)->getState(), nts::TRUE);
    cr_expect_eq(andComp.getPin(1)->getState(), nts::FALSE);
    cr_expect_eq(andComp.getPin(2)->getState(), nts::FALSE);
}

Test(ComponentAnd, FalseAndTrue)
{
    nts::ComponentAnd andComp("and");

    andComp.getPin(1)->setState(nts::TRUE);
    andComp.getPin(0)->setState(nts::FALSE);
    andComp.local_compute();
    cr_expect_eq(andComp.getPin(1)->getState(), nts::TRUE);
    cr_expect_eq(andComp.getPin(0)->getState(), nts::FALSE);
    cr_expect_eq(andComp.getPin(2)->getState(), nts::FALSE);
}

Test(ComponentAnd, FalseAndFalse)
{
    nts::ComponentAnd andComp("and");

    andComp.getPin(0)->setState(nts::FALSE);
    andComp.getPin(1)->setState(nts::FALSE);
    andComp.local_compute();
    cr_expect_eq(andComp.getPin(0)->getState(), nts::FALSE);
    cr_expect_eq(andComp.getPin(1)->getState(), nts::FALSE);
    cr_expect_eq(andComp.getPin(2)->getState(), nts::FALSE);
}

Test(ComponentAnd, TrueAndUndefined)
{
    nts::ComponentAnd andComp("and");

    andComp.getPin(0)->setState(nts::TRUE);
    andComp.getPin(1)->setState(nts::UNDEFINED);
    andComp.local_compute();
    cr_expect_eq(andComp.getPin(0)->getState(), nts::TRUE);
    cr_expect_eq(andComp.getPin(1)->getState(), nts::UNDEFINED);
    cr_expect_eq(andComp.getPin(2)->getState(), nts::UNDEFINED);
}

Test(ComponentAnd, FalseAndUndefined)
{
    nts::ComponentAnd andComp("and");

    andComp.getPin(0)->setState(nts::FALSE);
    andComp.getPin(1)->setState(nts::UNDEFINED);
    andComp.local_compute();
    cr_expect_eq(andComp.getPin(0)->getState(), nts::FALSE);
    cr_expect_eq(andComp.getPin(1)->getState(), nts::UNDEFINED);
    cr_expect_eq(andComp.getPin(2)->getState(), nts::FALSE);
}

Test(ComponentAnd, UndefinedAndUndefined)
{
    nts::ComponentAnd andComp("and");

    andComp.getPin(0)->setState(nts::UNDEFINED);
    andComp.getPin(1)->setState(nts::UNDEFINED);
    andComp.local_compute();
    cr_expect_eq(andComp.getPin(0)->getState(), nts::UNDEFINED);
    cr_expect_eq(andComp.getPin(1)->getState(), nts::UNDEFINED);
    cr_expect_eq(andComp.getPin(2)->getState(), nts::UNDEFINED);
}