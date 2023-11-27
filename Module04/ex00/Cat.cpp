/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:43:00 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/27 10:45:38 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Cat::Cat() {
	type = "Cat";
	std::cout << "A new kitty enters home! 🐈" << std::endl;
}

Cat::~Cat() {
	std::cout << "A cat leaves the house. 🐈" << std::endl;
}

void    makeSound() {
	std::cout << "Meow! Meow! 🔊" << std::endl;
}