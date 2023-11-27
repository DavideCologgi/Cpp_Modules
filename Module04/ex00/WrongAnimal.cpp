/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:54:56 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/27 11:37:53 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    type = "WrongAnimal";
    std::cout << "Wrong animal constructor" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "Wrong animal destructor" << std::endl;
}

void    WrongAnimal::makeSound() {
    std::cout << "Wrong animal makes a sound." << std::endl;
}

std::string WrongAnimal::getType() const {
    return (type);
}