/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:41:28 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/04 11:41:30 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& str, int n) :  name(str) {
	if (n < 1) {
		throw GradeTooHighException();
	} else if (n > 150) {
		throw GradeTooLowException();
	} else {
		grade = n;
	}
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
	return (name);
}

int         Bureaucrat::getGrade() const {
	return (grade);
}

void        Bureaucrat::gradeUp() {
	if (grade > 1) {
		grade--;
	} else {
		throw GradeTooHighException();
	}
}

void        Bureaucrat::gradeDown() {
	if (grade < 150 && grade > 0) {
		grade++;
	} else {
		throw GradeTooLowException();
	}
}

void		Bureaucrat::signForm(AForm& form) {
	form.beSigned(*this);
	if (form.getSign()) {
		std::cout << getName() << " signed " << form.getName() << std::endl;
	} else {
		std::cout << getName() << " couldn't sign " << form.getName()
			<< " because his grade is not high enough." << std::endl;
	}
}

void		Bureaucrat::executeForm(const AForm& form) {
	try {
		form.execute(*this);
	} catch (std::exception& e) {
		std::cout << name << " couldn't execute " << form.getName() 
			<< " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}