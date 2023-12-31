/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:09:50 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/23 10:34:50 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	ScavTrap	scavtrap1("Totti");
	ScavTrap	scavtrap2("Balotelli");

	scavtrap2.attack("Totti");
	scavtrap1.takeDamage(20);
	scavtrap1.beRepaired(50);
	scavtrap1.attack("Balotelli");
	scavtrap2.takeDamage(150);
	scavtrap2.attack("Totti");
	scavtrap1.guardGate();
	
	return (0);
}