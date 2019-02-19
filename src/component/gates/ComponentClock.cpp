/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentClock.cpp
*/

#include "ComponentClock.hpp"
#include "ComponentInput.hpp"
#include "ComponentOutput.hpp"
#include "ComponentSplit.hpp"

nts::ComponentClock::State nts::ComponentClock::upDown = nts::ComponentClock::DOWN;

nts::ComponentClock::ComponentClock(const std::string &name) :
	ComponentInput(name)
{
	clockState = UNDEFINED;
}

nts::Tristate nts::ComponentClock::localCompute()
{
	if (clockState == UNDEFINED)
		clockState = upDown == DOWN ? _pins[0]->getState() : !_pins[0]->getState();
	_pins[0]->setState(upDown == UP ? !clockState : clockState);
	return (_pins[0]->getState());
}

void nts::ComponentClock::dump()
{
}

nts::ComponentClock::State nts::operator!(nts::ComponentClock::State upDown)
{
	return upDown == ComponentClock::UP ? ComponentClock::DOWN : ComponentClock::UP;
}