/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:26:07 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/28 09:56:26 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << "Wrong cat constructor" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "Wrong cat destructor" << std::endl;
}

void    WrongCat::makeSound() const {
    std::cout << "Wrong cat makes a SQUIT sound?!" << std::endl;
}