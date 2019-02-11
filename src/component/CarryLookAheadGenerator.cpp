/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** CarryLookAheadGenerator.cpp,
*/

#include "CarryLookAheadGenerator.hpp"
#include "ComponentXOr.hpp"
#include "ComponentXAnd.hpp"
#include "ComponentSplit.hpp"

nts::CarryLookAheadGenerator::CarryLookAheadGenerator(const std::string &name) : ACircuit(name)
{
	for (int j = 4; j >= 1; --j)
		_components.push_back(std::make_unique<ComponentXOr>("XOr" + std::to_string(j + 1), j + 1));
	for (size_t j = 4; j >= 1; --j) {
		for (size_t i = 0; i < j; ++i) {
			_components.push_back(std::make_unique<ComponentXAnd>("XAnd" + std::to_string(j)
									      + " " + std::to_string(j + 1 - i),
				j + 1 - i));
			_components[j]->setLink(j, *_components[_components.size() - 1], j + 1 - i);
		}
	}

	create_carries();
	link_carries();
	create_results();
	link_results();
}

void nts::CarryLookAheadGenerator::create_carries()
{
	_components.push_back(std::make_unique<ComponentSplit>("splitC0", 4));
	_pins.push_back(_components[_components.size() - 1]->getPin(0));
	for (int GIdx = 0; GIdx < 4; ++GIdx) {
		_components.push_back(std::make_unique<ComponentSplit>("split G" + std::to_string(GIdx), 4 - GIdx + 1));
		_pins.push_back(_components[_components.size() - 1]->getPin(0));
	}
}

void nts::CarryLookAheadGenerator::create_results()
{
	for (int SumIdx = 0; SumIdx < 4; ++SumIdx) {
		_components.push_back(std::make_unique<ComponentSplit>("split S" + std::to_string(SumIdx),
			(SumIdx + 1) * (4 - SumIdx)));
		_pins.push_back(_components[_components.size() - 1]->getPin(0));
	}
}

nts::IComponent &nts::CarryLookAheadGenerator::getGate(int blockIdx, int gateIdx)
{
	return _components[];
}

void nts::CarryLookAheadGenerator::link_carries()
{
	_components[_components.size() - 1]->setLink(1, *_components[0], 0);

	_components[_components.size() - 2]->setLink(1, *_components[1], 0);
	_components[_components.size() - 2]->setLink(2, getGate(4, 4), 0);

	_components[_components.size() - 3]->setLink(1, *_components[2], 0);
	_components[_components.size() - 3]->setLink(2, getGate(3, 3), 0);
	_components[_components.size() - 3]->setLink(2, getGate(4, 3), 0);

	_components[_components.size() - 3]->setLink(1, *_components[2], 0);
	_components[_components.size() - 3]->setLink(2, getGate(3, 3), 0);
	_components[_components.size() - 3]->setLink(3, getGate(4, 3), 0);

	_components[_components.size() - 4]->setLink(1, *_components[3], 0);
	_components[_components.size() - 4]->setLink(2, getGate(2, 2), 0);
	_components[_components.size() - 4]->setLink(3, getGate(3, 2), 0);
	_components[_components.size() - 4]->setLink(4, getGate(4, 2), 0);

	_components[_components.size() - 5]->setLink(1, getGate(1, 2), 0);
	_components[_components.size() - 5]->setLink(2, getGate(2, 2), 0);
	_components[_components.size() - 5]->setLink(3, getGate(3, 2), 0);
	_components[_components.size() - 5]->setLink(4, getGate(4, 2), 0);
}

/*
 * Chaque Pi va dans les i + 1 plus grandes portes d'un ensemble
 * Chaque retenue Gi (comptant C0) va à la porte i d'un ensemble et à sa OR
 * Pi number = (i + 1) * (size - i)
 * Gi number = size - i + 1 (sauf C0)
 * Commencant à 0:
 *
 * Pour trouver Ci:
 * 	la premiere (la plus grande):
 * 	C0 Pi
 * 	La porte de taille j prendra en input:
 * 		Ci Pi
 *
 * Gi a chaque porte i + 1 d'un ensemble
 * Pi à chaque porte de l'ensemble i
 * C0 à toutes les plus grandes

 */