/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** ComponentSplit.hpp,
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENTSPLIT_HPP
#define OOP_NANOTEKSPICE_2018_COMPONENTSPLIT_HPP

#include "AComponent.hpp"

namespace nts {
	class ComponentSplit : public AComponent {
	public:
		ComponentSplit(const std::string &name, size_t signal_split);

		void dump() override;
		Tristate localCompute() override;
	private:
		size_t _splitNb;
	};
}

#endif //OOP_NANOTEKSPICE_2018_COMPONENTSPLIT_HPP
