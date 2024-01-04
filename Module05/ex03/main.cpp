/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:57:14 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/04 12:17:07 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	try {
		Bureaucrat	b1("lottavi", 100);
		Bureaucrat	b2("dcologgi", 1);
		Bureaucrat	b3("fcarlucc", 2);

		ShrubberyCreationForm	shrub("home");
		RobotomyRequestForm		rob("Alexa");
		PresidentialPardonForm	pres("Pres");
		
		b1.signForm(shrub);
		b1.executeForm(shrub);
		b1.signForm(rob);
		b1.executeForm(rob);
		b2.signForm(rob);
		b2.executeForm(rob);
		b3.signForm(pres);
		b2.executeForm(pres);
		
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return (0);
}