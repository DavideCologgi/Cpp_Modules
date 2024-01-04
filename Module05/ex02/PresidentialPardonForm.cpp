/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:46:55 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/04 12:09:11 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string targ) :
    AForm(targ, 25, 5) {
        this->target = targ;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void    PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    if (this->getSign() == false) {
        throw FormNotSignedException();
    }
    else if (executor.getGrade() > this->getExeGrade()) {
        throw GradeTooLowException();
    }

    std::cout << getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}