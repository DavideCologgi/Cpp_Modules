/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:53:22 by dcologgi          #+#    #+#             */
/*   Updated: 2023/12/20 15:53:37 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : sign(false), sign_grade(0), exe_grade(0) {}

AForm::AForm(const std::string& form, const int grade, const int exe)
	: name(form), sign(false), sign_grade(grade), exe_grade(exe) {
		if (grade < 1 || exe < 1) {
			throw GradeTooHighException();
		} else if (grade > 150 || exe > 150) {
			throw GradeTooLowException();
		}
}

AForm::~AForm() {}

std::string	AForm::getName() const {
	return (name);
}

bool		AForm::getSign() const {
	return (sign);
}

int			AForm::getSignGrade() const {
	return (sign_grade);
}

int			AForm::getExeGrade() const {
	return (exe_grade);
}

void		AForm::setSign(bool firmed) {
	sign = firmed;
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << form.getName() << ", form grade: " << form.getSignGrade() << ", execution grade: "
		<< form.getExeGrade() << ", signed = " << form.getSign();
	return (os);
}