/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:31:09 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/09 14:44:04 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    // Creazione oggetto con allocazione nella memoria heap
    Zombie* heapZombie = newZombie("Heap");
    heapZombie->announce();
    delete heapZombie;

    // Creazione oggetto con allocazione nella memoria stack
    randomChump("Stack");

    return (0);
}