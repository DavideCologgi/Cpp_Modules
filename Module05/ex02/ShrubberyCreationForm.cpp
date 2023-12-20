/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:12:51 by dcologgi          #+#    #+#             */
/*   Updated: 2023/12/20 15:58:03 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target_name)
	: AForm(target_name + "_shrubbery", 145, 137), target(target_name)
{
		std::cout << "ShrubberyForm successfully created!" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyForm destroyed." << std::endl;
}

void	ShrubberyCreationForm::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= getSignGrade()) {
		setSign(true);
	}
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	// if (executor.getGrade() <= this->getExeGrade() && this->getSign()) {
	// 	std::cout << this->target << "_shrubbery has been created!" << std::endl;
	// 	std::string full_name = this->target + "_shrubbery";
	// 	std::ofstream outputFile(full_name);
	// 	outputFile << 
	// }	
	std::cout << "ciao"<< executor << std::endl;
}
