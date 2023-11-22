/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:09:50 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/22 16:42:56 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
	FragTrap fragtrap1("Johnny Bravo");
	FragTrap fragtrap2("Mojo Jojo");

	fragtrap2.attack("Superchicca");
	fragtrap2.takeDamage(20);
	fragtrap2.beRepaired(30);
	fragtrap1.attack("Bella ragazza");
	fragtrap1.takeDamage(2000);
	fragtrap1.attack("Mojo Jojo");
	fragtrap1.highFivesGuys();

	return (0);
}