/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:21:26 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/23 11:22:27 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& newName) : ClapTrap(newName) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " is ready to run on the left wing!"
        << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << name << " scored a hat-trick and got subbed off"
        << std::endl;
}

void    ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in GateKeeper mode!" << std::endl;
}
