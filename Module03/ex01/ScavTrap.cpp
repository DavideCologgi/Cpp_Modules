/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:21:26 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/27 14:13:59 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap " << name << " is ready to destroy everything!"
		<< std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << name << " finished its job and can die in peace"
		<< std::endl;
}

void    ScavTrap::guardGate() {
	std::cout << "ScavTrap " << name << " is now in GateKeeper mode!" << std::endl;
}

void    ScavTrap::attack(const std::string& target) {
	if (hitPoints == 0 || energyPoints == 0) {
		std::cout << "ScavTrap " << name << " can't attack. No hit points or energy left!"
			<< std::endl;
			return ;
	}
	energyPoints--;
	std::cout << "ScavTrap " << name << " attacks " << target << " and deals "
		<< attackDamage << " damage/damages" << std::endl;
}
