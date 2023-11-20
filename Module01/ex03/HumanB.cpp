/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:11:07 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/16 12:25:24 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : p_name(name) {
    std::cout << name << " joins war with no weapon...strange choice"
        << std::endl;
}

HumanB::~HumanB() {
    std::cout << this->p_name
        << " unfortunately died because of inexperience...poor boy" << std::endl;
}

void    HumanB::attack() {
    std::cout << this->p_name << " attacks with their "
        << this->p_weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon) {
    this->p_weapon = &weapon;
}