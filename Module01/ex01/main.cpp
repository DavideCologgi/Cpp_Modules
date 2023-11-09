/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:01:04 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/09 15:29:12 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    int     hordeSize = 5;
    Zombie* zombieArmy = zombieHorde(hordeSize, "Horde");

    // Test di announce
    for (int i = 0; i < hordeSize; i++) {
        zombieArmy[i].announce();
    }

    delete[] zombieArmy;

    return (0);
}