/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:06:52 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/09 15:44:29 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name) {
    Zombie* horde = new Zombie[n];
    
    for (int i = 0; i < n; i++) {
        horde[i].setName(name);
    }
    return horde;
}