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
	class ComponentOutput : public AComponent {
	public:
		explicit ComponentOutput(const std::string &name);

		Tristate localCompute() override;
		void dump() override;
	};
}

#endif
