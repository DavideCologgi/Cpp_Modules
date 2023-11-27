/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:26:07 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/27 13:51:10 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "Wrong cat constructor" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "Wrong cat destructor" << std::endl;
}

void    WrongCat::makeSound() {
    std::cout << "Wrong cat makes a SQUIT! sound." << std::endl;
}