/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:27:08 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/28 14:08:44 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : brain(new Brain()) {
	type = "Dog";
	std::cout << "A new doggo says hi! 🐕" << std::endl;
}

Dog::Dog(const Dog& other) : brain(new Brain(*(other.brain))) {
	type = other.type;
    std::cout << "Dog copy constructor" << std::endl;
}

Dog::~Dog() {
	delete brain;
	std::cout << "A doggo says goodbye. 🐕" << std::endl;
}

void    Dog::makeSound() const {
	std::cout << "Woof! Woooof! 🔊" << std::endl;
}

Dog*	Dog::createDog() {
	return (new Dog());
}

Dog* 	Dog::clone() const {
    return (new Dog(*this));
}