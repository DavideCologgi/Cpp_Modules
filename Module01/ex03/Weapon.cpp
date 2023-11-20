/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:07:17 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/16 12:11:00 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string startType): type(startType){}

Weapon::~Weapon() {}

const std::string&  Weapon::getType() {
    return (this->type);
}

void    Weapon::setType(std::string newType) {
    this->type = newType;
}
