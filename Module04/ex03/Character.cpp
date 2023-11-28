/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:41:38 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/28 16:43:23 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const &name) : p_name(name) {
    for (int i = 0; i < 4; ++i) {
        inventory[i] = NULL;
    }
}

Character::~Character() {
    for (int i = 0; i < 4; ++i) {
        delete inventory[i];
    }
}

std::string const   &Character::getName() const {
    return (p_name);
}

void                Character::equip(AMateria *m) {
    for (int i = 0; i < 4; ++i) {
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            std::cout << m->getType() << " equipped in slot " << i << std::endl;
            return;
        }
    }
    std::cout << "Inventory is full, cannot equip " << m->getType() << std::endl;
}

void                Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && inventory[idx] != NULL) {
        std::cout << inventory[idx]->getType() << " unequipped from slot "
            << idx << std::endl;
        inventory[idx] = NULL;
    } else {
        std::cout << "Invalid slot or empty slot, cannot unequip!" << std::endl;  
    }
}

void                Character::use(int idx, ICharacter &target) {
    if (idx >= 0 && idx < 4 && inventory[idx] != NULL) {
        inventory[idx]->use(target);
    } else {
        std::cout << "Invalid slot or empty slot, cannot use!" << std::endl;
    }
}