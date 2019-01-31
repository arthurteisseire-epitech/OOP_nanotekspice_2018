/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentOutput.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENTOUTPUT_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENTOUTPUT_HPP

#include "AComponent.hpp"

namespace nts {
	class ComponentOuput : public AComponent {
	public:
		explicit ComponentOuput(const std::string &name);

		Tristate local_compute() override;
		void dump() override;
	};
}

#endif
