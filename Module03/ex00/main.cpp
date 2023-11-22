/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:09:50 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/22 16:28:05 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap claptrap1("Tom");
	ClapTrap claptrap2("Jerry");

	claptrap1.attack("Jerry");
	claptrap2.takeDamage(3);
	claptrap2.beRepaired(2);
	claptrap2.attack("Tom");
	claptrap1.takeDamage(12);
	claptrap1.attack("Jerry");
	claptrap2.beRepaired(2);
	claptrap2.attack("Tom");
	claptrap2.attack("Tom");
	claptrap2.attack("Tom");
	claptrap2.attack("Tom");
	claptrap2.attack("Tom");
	claptrap2.attack("Tom");
	claptrap2.attack("Tom");
	claptrap2.attack("Tom");

	return (0);
}