/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentClock.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENTCLOCK_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENTCLOCK_HPP

#include "ComponentInput.hpp"

namespace nts {
	class ComponentClock : public ComponentInput {
	public:
		enum State {UP, DOWN};
		explicit ComponentClock(const std::string &name);
		Tristate localCompute() override;
		void dump() override;
		static State upDown;
		Tristate clockState;
	};
	ComponentClock::State operator!(ComponentClock::State upDown);
}

#endif
