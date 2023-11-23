/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:09:50 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/23 10:35:30 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	FragTrap	fragtrap1("Johnny Bravo");
	FragTrap	fragtrap2("Mojo Jojo");
	ScavTrap	scavtrap1("Mbappé");

	scavtrap1.guardGate();
	fragtrap2.attack("Superchicca");
	fragtrap2.takeDamage(20);
	fragtrap2.beRepaired(30);
	fragtrap1.attack("Bella ragazza");
	fragtrap1.takeDamage(2000);
	fragtrap1.attack("Mojo Jojo");
	fragtrap1.highFivesGuys();

	return (0);
}