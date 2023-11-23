/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:09:50 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/23 11:14:44 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
	FragTrap	fragtrap1("Johnny Bravo");
	FragTrap	fragtrap2("Mojo Jojo");
	ScavTrap	scavtrap1("Mbappé");
	DiamondTrap	diamondtrap1("Steve");

	scavtrap1.guardGate();
	fragtrap2.attack("Superchicca");
	fragtrap2.takeDamage(20);
	fragtrap2.beRepaired(30);
	fragtrap1.attack("Bella ragazza");
	fragtrap1.takeDamage(2000);
	fragtrap1.attack("Mojo Jojo");
	fragtrap1.highFivesGuys();
	diamondtrap1.whoAmI();
	diamondtrap1.attack("Mojo Jojo");
	diamondtrap1.takeDamage(30);
	diamondtrap1.beRepaired(40);
	diamondtrap1.guardGate();
	diamondtrap1.highFivesGuys();

	return (0);
}