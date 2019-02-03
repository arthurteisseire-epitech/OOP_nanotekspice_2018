/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Exec.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_EXEC_HPP
#define OOP_NANOTEKSPICE_2018_EXEC_HPP

#include "IComponent.hpp"

namespace nts {
	class Exec {
	public:
		static void compute(const std::vector<std::unique_ptr<IComponent>> &components);
		static void display(const std::vector<std::unique_ptr<IComponent>> &components);
	};
}

#endif
