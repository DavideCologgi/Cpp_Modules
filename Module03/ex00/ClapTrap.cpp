/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:10:12 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/22 15:54:41 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string clap_name) : name(clap_name), hitPoints(10),
	energyPoints(10), attackDamage(0) {
		std::cout << "ClapTrap " << name << " joins the battle!" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << " dies" << std::endl;
}

void    ClapTrap::attack(const std::string& target) {
	if (hitPoints == 0 || energyPoints == 0) {
		std::cout << "ClapTrap " << name << " can't attack. No hit points or energy left!"
			<< std::endl;
			return ;
	}
	energyPoints--;
	std::cout << "ClapTrap " << name << " attacks " << target << " and deals "
		<< attackDamage << " damage/damages" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints == 0) {
		std::cout << "ClapTrap " << name <<
			" can't take damage. No hit points left!" << std::endl;
        return;
	}
	if (amount > hitPoints) {
		hitPoints = 0;
	} else {
		hitPoints -= amount;
	}
	std::cout << "ClapTrap " << name << " takes " << amount <<
		" points of damage! Current hit points: " << hitPoints << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (hitPoints == 0) {
		std::cout << "ClapTrap " << name <<
			" can't be repaired. No hit points left!" << std::endl;
		return ;
	}
	energyPoints--;
	hitPoints += amount;
	if (hitPoints > 10) {
		hitPoints = 10;
	}
	std::cout << "ClapTrap " << name << " is repaired for " << amount <<
		" points! Current hit points: " << hitPoints << std::endl;
}