/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:59:20 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/16 12:25:45 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : p_name(name), p_weapon(weapon) {
    std::cout << name << " joins the battle with a "
        << weapon.getType() << std::endl;
}

HumanA::~HumanA() {
    std::cout << this->p_name << " unfortunately died from the recoil"
        << std::endl;
}

void    HumanA::attack() {
    std::cout << this->p_name << " attacks with their "
        << this->p_weapon.getType() << std::endl;
}

void    HumanA::setWeapon(Weapon weapon) {
    this->p_weapon = weapon;
}