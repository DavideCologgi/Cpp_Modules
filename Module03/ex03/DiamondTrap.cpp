/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:45:41 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/23 11:14:15 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& newName)
    : ClapTrap(newName + "_clap_name"),  ScavTrap(newName), FragTrap(newName) {
    this->name = newName;
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;

    std::cout << "DiamondTrap " << name << " entered the arena!" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << name << " says goodbye!" << std::endl;
}

void    DiamondTrap::whoAmI() {
    std::cout << "I am DiamondTrap " << name << " and my ClapTrap name is "
        << ClapTrap::name << std::endl;
}