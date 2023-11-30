/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:57:14 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/30 14:53:40 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat	b1("Salvini", 150);
		Bureaucrat	b2("Mattarella", 1);

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		
		//b1.gradeDown();
		b1.gradeUp();
		std::cout << b1 << std::endl;
		
		//b2.gradeUp();
		b2.gradeDown();
		std::cout << b2 << std::endl;
		
		Bureaucrat	b3("Meloni", 155);
		Bureaucrat	b4("Mancini", 0);
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return (0);
}