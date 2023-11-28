/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:56:52 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/28 14:03:04 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "AAnimal.hpp"

Brain::Brain() {  
    std::cout << "The brain of the animal starts working." << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain stopped working." << std::endl;
}