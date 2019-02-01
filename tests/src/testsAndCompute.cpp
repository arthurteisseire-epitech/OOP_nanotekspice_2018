/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice_2018
** File description:
** Created by Adrien FABRE,
*/

#include <criterion/criterion.h>
#include "ComponentInput.hpp"
#include "ComponentOutput.hpp"
#include "ComponentAnd.hpp"

Test(AndCompute, TrueTrue)
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
    cr_expect_eq(out.getPin(0)->getState(), nts::TRUE);
}

Test(AndCompute, TrueFalse)
{
    nts::ComponentInput in("in");
    nts::ComponentInput in2("in2");
    nts::ComponentOutput out("out");
    nts::ComponentAnd andComp("and");

    out.setLink(0, andComp, 2);
    andComp.setLink(0, in, 0);
    andComp.setLink(1, in2, 0);

    in.getPin(0)->setState(nts::TRUE);
    in2.getPin(0)->setState(nts::FALSE);
    out.compute(0);
    cr_expect_eq(out.getPin(0)->getState(), nts::FALSE);
}

Test(AndCompute, FalseTrue)
{
    nts::ComponentInput in("in");
    nts::ComponentInput in2("in2");
    nts::ComponentOutput out("out");
    nts::ComponentAnd andComp("and");

    out.setLink(0, andComp, 2);
    andComp.setLink(0, in, 0);
    andComp.setLink(1, in2, 0);

    in.getPin(0)->setState(nts::FALSE);
    in2.getPin(0)->setState(nts::TRUE);
    out.compute(0);
    cr_expect_eq(out.getPin(0)->getState(), nts::FALSE);
}

Test(AndCompute, FalseFale)
{
    nts::ComponentInput in("in");
    nts::ComponentInput in2("in2");
    nts::ComponentOutput out("out");
    nts::ComponentAnd andComp("and");

    out.setLink(0, andComp, 2);
    andComp.setLink(0, in, 0);
    andComp.setLink(1, in2, 0);

    in.getPin(0)->setState(nts::FALSE);
    in2.getPin(0)->setState(nts::FALSE);
    out.compute(0);
    cr_expect_eq(out.getPin(0)->getState(), nts::FALSE);
}

Test(AndCompute, TrueUndefined)
{
    nts::ComponentInput in("in");
    nts::ComponentInput in2("in2");
    nts::ComponentOutput out("out");
    nts::ComponentAnd andComp("and");

    out.setLink(0, andComp, 2);
    andComp.setLink(0, in, 0);
    andComp.setLink(1, in2, 0);

    in.getPin(0)->setState(nts::TRUE);
    in2.getPin(0)->setState(nts::UNDEFINED);
    out.compute(0);
    cr_expect_eq(out.getPin(0)->getState(), nts::UNDEFINED);
}

Test(AndCompute, UndefinedTrue)
{
    nts::ComponentInput in("in");
    nts::ComponentInput in2("in2");
    nts::ComponentOutput out("out");
    nts::ComponentAnd andComp("and");

    out.setLink(0, andComp, 2);
    andComp.setLink(0, in, 0);
    andComp.setLink(1, in2, 0);

    in.getPin(0)->setState(nts::UNDEFINED);
    in2.getPin(0)->setState(nts::TRUE);
    out.compute(0);
    cr_expect_eq(out.getPin(0)->getState(), nts::UNDEFINED);
}

Test(AndCompute, FalseUndefined)
{
    nts::ComponentInput in("in");
    nts::ComponentInput in2("in2");
    nts::ComponentOutput out("out");
    nts::ComponentAnd andComp("and");

    out.setLink(0, andComp, 2);
    andComp.setLink(0, in, 0);
    andComp.setLink(1, in2, 0);

    in.getPin(0)->setState(nts::FALSE);
    in2.getPin(0)->setState(nts::UNDEFINED);
    out.compute(0);
    cr_expect_eq(out.getPin(0)->getState(), nts::FALSE);
}

Test(AndCompute, UndefinedFalse)
{
    nts::ComponentInput in("in");
    nts::ComponentInput in2("in2");
    nts::ComponentOutput out("out");
    nts::ComponentAnd andComp("and");

    out.setLink(0, andComp, 2);
    andComp.setLink(0, in, 0);
    andComp.setLink(1, in2, 0);

    in.getPin(0)->setState(nts::UNDEFINED);
    in2.getPin(0)->setState(nts::FALSE);
    out.compute(0);
    cr_expect_eq(out.getPin(0)->getState(), nts::FALSE);
}

Test(AndCompute, UndefinedUndefined)
{
    nts::ComponentInput in("in");
    nts::ComponentInput in2("in2");
    nts::ComponentOutput out("out");
    nts::ComponentAnd andComp("and");

    out.setLink(0, andComp, 2);
    andComp.setLink(0, in, 0);
    andComp.setLink(1, in2, 0);

    in.getPin(0)->setState(nts::UNDEFINED);
    in2.getPin(0)->setState(nts::UNDEFINED);
    out.compute(0);
    cr_expect_eq(out.getPin(0)->getState(), nts::UNDEFINED);
}