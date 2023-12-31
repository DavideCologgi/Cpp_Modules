/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:14:11 by dcologgi          #+#    #+#             */
/*   Updated: 2023/12/11 12:55:28 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string& form, const int grade, const int exe)
	: name(form), sign(false), sign_grade(grade), exe_grade(exe) {
		if (grade < 1 || exe < 1) {
			throw GradeTooHighException();
		} else if (grade > 150 || exe > 150) {
			throw GradeTooLowException();
		}
}

Form::~Form() {}

std::string	Form::getName() const {
	return (name);
}

bool		Form::getSign() const {
	return (sign);
}

int			Form::getSignGrade() const {
	return (sign_grade);
}

int			Form::getExeGrade() const {
	return (exe_grade);
}

void		Form::setSign(bool firmed) {
	sign = firmed;
}

void		Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= sign_grade) {
		setSign(true);
	}
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << form.getName() << ", form grade: " << form.getSignGrade() << ", execution grade: "
		<< form.getExeGrade() << ", signed = " << form.getSign();
	return (os);
}