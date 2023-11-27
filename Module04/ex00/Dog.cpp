/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:27:08 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/27 10:45:34 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Dog::Dog() {
	type = "Dog";
	std::cout << "A new doggo says hi! 🐕" << std::endl;
}

Dog::~Dog() {
	std::cout << "A doggo says goodbye. 🐕" << std::endl;
}

void    makeSound() {
	std::cout << "Woof! Woooof! 🔊" << std::endl;
}