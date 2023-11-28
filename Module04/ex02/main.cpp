/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:29:48 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/28 14:51:22 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {
	const int	arraySize = 6;
	AAnimal*	animalArray[arraySize];
		
	for (int i = 0; i < arraySize / 2; ++i) {
		animalArray[i] = new Dog();
		animalArray[i + arraySize / 2] = new Cat();
	}
	for (int i = 0; i < arraySize; ++i) {
		delete animalArray[i];
	}
	return (0);	
}