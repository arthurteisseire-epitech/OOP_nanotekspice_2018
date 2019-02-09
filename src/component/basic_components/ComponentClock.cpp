/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentClock.cpp
*/

#include "ComponentClock.hpp"

nts::ComponentClock::State nts::ComponentClock::upDown = nts::ComponentClock::DOWN;

nts::ComponentClock::ComponentClock(const std::string &name) :
	ComponentInput(name)
{
}

nts::Tristate nts::ComponentClock::localCompute()
{
	if (upDown == UP)
		return !_pins[0]->getState();
	return _pins[0]->getState();
}

nts::ComponentClock::State nts::operator!(nts::ComponentClock::State upDown)
{
	return upDown == ComponentClock::UP ? ComponentClock::DOWN : ComponentClock::UP;
}
