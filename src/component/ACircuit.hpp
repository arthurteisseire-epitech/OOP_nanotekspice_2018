/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ACircuit.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_ACIRCUIT_HPP
#define OOP_NANOTEKSPICE_2018_ACIRCUIT_HPP

#include "AComponent.hpp"

namespace nts {
	class ACircuit : public AComponent {
	public:
		explicit ACircuit(const std::string &name);
		std::vector<std::unique_ptr<IComponent>> &getComponents() {return _components;}
	protected:
		std::vector<std::unique_ptr<IComponent>> _components;
	};
}

#endif
