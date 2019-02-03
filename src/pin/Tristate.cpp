/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Tristate.cpp
*/

#include "Tristate.hpp"

nts::Tristate nts::operator||(nts::Tristate a, nts::Tristate b)
{
	if (a == TRUE || b == TRUE)
		return TRUE;
	if (a == UNDEFINED || b == UNDEFINED)
		return UNDEFINED;
	return FALSE;
}

nts::Tristate nts::operator&&(nts::Tristate a, nts::Tristate b)
{
	if (a == FALSE || b == FALSE)
		return FALSE;
	if (a == UNDEFINED || b == UNDEFINED)
		return UNDEFINED;
	return TRUE;
}

nts::Tristate nts::operator^(nts::Tristate a, nts::Tristate b)
{
	if (a == UNDEFINED || b == UNDEFINED)
		return UNDEFINED;
	if (a == b)
		return FALSE;
	return TRUE;
}