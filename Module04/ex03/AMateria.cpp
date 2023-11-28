/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:24:54 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/28 16:41:30 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const & type) : p_type(type) {}

AMateria::~AMateria() {}

std::string const   &AMateria::getType() const
{
    return (p_type);
}

void                AMateria::use(ICharacter &target)
{
    std::cout << "* uses " << getType() << " on " << target.getName()
        << " *" << std::endl;
}