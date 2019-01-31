/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice_2018
** File description:
** Created by Adrien FABRE,
*/

#include <criterion/criterion.h>
#include "ComponentOutput.hpp"
#include "ComponentInput.hpp"
#include "ComponentAnd.hpp"

Test(LinkedComponents, TwoInputsOneAndOneOutput)
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

	cr_expect_eq(andComp.getPin(0)->getState(), nts::TRUE);
	cr_expect_eq(andComp.getPin(1)->getState(), nts::TRUE);
	cr_expect_eq(andComp.getPin(2)->getState(), nts::TRUE);
	cr_expect_eq(in.getPin(0)->getState(), nts::TRUE);
	cr_expect_eq(in2.getPin(0)->getState(), nts::TRUE);
	cr_expect_eq(out.getPin(0)->getState(), nts::TRUE);
}

Test(LinkedComponents, OneInputOneAndOneOutput)
{
    nts::ComponentAnd andComp("and1");
    nts::ComponentOutput out("out");
    nts::ComponentInput in("in2");

    andComp.setLink(0, in, 0);
    andComp.setLink(1, in, 0);
    andComp.setLink(2, out, 0);
    in.getPin(0)->setState(nts::TRUE);
    out.getPin(0)->setState(nts::TRUE);
    cr_expect_eq(andComp.getPin(0)->getState(), nts::TRUE);
    cr_expect_eq(andComp.getPin(1)->getState(), nts::TRUE);
    cr_expect_eq(andComp.getPin(2)->getState(), nts::TRUE);
}

Test(LinkedComponents, twoInputsThreeAndOneOutput)
{
    nts::ComponentAnd andComp("and1");
    nts::ComponentAnd andComp2("and2");
    nts::ComponentAnd andFinal("and3");
    nts::ComponentOutput out("out");
    nts::ComponentInput in("in2");
    nts::ComponentInput in2("in2");

    andComp.setLink(0, in, 0);
    andComp.setLink(1, in2, 0);

    andComp2.setLink(0, in, 0);
    andComp2.setLink(1, andComp, 2);

    andFinal.setLink(0, andComp, 2);
    andFinal.setLink(1, andComp2, 2);

    out.setLink(0, andFinal, 2);

    in.getPin(0)->setState(nts::TRUE);
    in2.getPin(0)->setState(nts::FALSE);

    andComp.getPin(2)->setState(nts::FALSE);
    andComp2.getPin(2)->setState(nts::FALSE);
    andFinal.getPin(2)->setState(nts::FALSE);

    cr_expect_eq(andComp.getPin(0)->getState(), nts::TRUE);
    cr_expect_eq(andComp.getPin(1)->getState(), nts::FALSE);
    cr_expect_eq(andComp2.getPin(0)->getState(), nts::TRUE);
    cr_expect_eq(andComp2.getPin(1)->getState(), nts::FALSE);
    cr_expect_eq(andFinal.getPin(0)->getState(), nts::FALSE);
    cr_expect_eq(andFinal.getPin(1)->getState(), nts::FALSE);
    cr_expect_eq(out.getPin(0)->getState(), nts::FALSE);
}