/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:29:42 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/28 16:40:52 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

AMateria    *Ice::clone() const {
    return (new Ice(*this));
}

void        Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName()
        << " *" << std::endl;
}