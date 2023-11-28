/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:38:21 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/28 14:14:06 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::~AAnimal() {
	std::cout << "An animal of the farm dies 🪦" << std::endl;
}

void	AAnimal::makeSound() const {
	std::cout << "You hear an animal sound from afar but you can't recognize it. 🔊"
		<< std::endl;
}

const std::string&	AAnimal::getType() const {
	return (type);
}

AAnimal*	AAnimal::createAnimal() {
	return (NULL);
}