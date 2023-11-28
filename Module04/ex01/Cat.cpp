/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:43:00 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/28 13:55:56 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : brain(new Brain()) {
	type = "Cat";
	std::cout << "A new kitty enters home! 🐈" << std::endl;
}

Cat::Cat(const Cat& other) : brain(new Brain(*(other.brain))) {
	type = other.type;
	std::cout << "Cat copy constructor" << std::endl;
}

Cat::~Cat() {
	delete brain;
	std::cout << "A cat leaves the house. 🐈" << std::endl;
}

void    Cat::makeSound() const {
	std::cout << "Meow! Meow! 🔊" << std::endl;
}

Cat*	Cat::clone() const {
	return (new Cat(*this));
}