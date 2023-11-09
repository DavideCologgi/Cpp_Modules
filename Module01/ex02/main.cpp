/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:48:05 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/09 16:02:21 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main () {
	std::string brain = "HI THIS IS BRAIN";     
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;
	
	// Print indirizzi di memoria
	std::cout << "string: " << &brain << std::endl;
	std::cout << "pointer: " << stringPTR << std::endl;
	std::cout << "reference: " << &stringREF << std::endl;
	std::cout << std::endl;

	// Print valore
	std::cout << "string: " << brain << std::endl;
	std::cout << "pointer: " << *stringPTR << std::endl;
	std::cout << "reference: " << stringREF << std::endl;
	
	return (0);
}