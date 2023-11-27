/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:38:21 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/27 10:49:34 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	type = "Generic animal";
	std::cout << "A new animal joins the farm!" << std::endl;
}

Animal::~Animal() {
	std::cout << "An animal of the farm dies 🪦" << std::endl;
}

void	Animal::makeSound() {
	std::cout << "You hear an animal sound from afar but you can't recognize it. 🔊"
		<< std::endl;
}

std::string	Animal::getType() const {
	return (type);
}