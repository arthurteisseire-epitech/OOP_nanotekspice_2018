/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** CarryLookAheadGenerator.hpp,
*/

#ifndef OOP_NANOTEKSPICE_2018_CARRYLOOKAHEADGENERATOR_HPP
#define OOP_NANOTEKSPICE_2018_CARRYLOOKAHEADGENERATOR_HPP

#include "ACircuit.hpp"

namespace nts {
	class CarryLookAheadGenerator : public ACircuit {
	public:
		CarryLookAheadGenerator(const std::string &name);
	private:
		void create_carries();
		void link_carries();
		void create_results();
		void link_results();
		IComponent &getGate(int blockIdx, int gateIdx);
	};
}

#endif //OOP_NANOTEKSPICE_2018_CARRYLOOKAHEADGENERATOR_HPP
