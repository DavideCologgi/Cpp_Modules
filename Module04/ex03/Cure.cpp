/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:35:41 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/28 16:41:01 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::~Cure() {}

AMateria    *Cure::clone() const {
    return (new Cure(*this));
}

void        Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}