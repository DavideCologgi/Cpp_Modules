/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:57:14 by dcologgi          #+#    #+#             */
/*   Updated: 2023/12/11 12:55:59 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat	b1("Salvini", 100);
		Bureaucrat	b2("Mattarella", 1);

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		
		//b1.gradeDown();
		b1.gradeUp();
		std::cout << b1 << std::endl;
		
		//b2.gradeUp();
		b2.gradeDown();
		std::cout << b2 << std::endl;
		
		Form	f1("Blocco navale", 90, 50);
		Form	f2("Taglio delle accise", 100, 150);

		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
		
		//Form	f3("Riforma sul nucleare", 0, 1);
		
		b1.signForm(f1);
		b2.signForm(f2);
		
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return (0);
}