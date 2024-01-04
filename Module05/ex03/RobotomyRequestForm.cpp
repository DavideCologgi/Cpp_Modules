/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:19:59 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/04 11:38:09 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string targ) :
    AForm(targ, 72, 45) {
        this->target = targ;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void    RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (this->getSign() == false) {
        throw FormNotSignedException();
    }
    else if (executor.getGrade() > this->getExeGrade()) {
        throw GradeTooLowException();
    }

    std::srand(static_cast<unsigned int>(std::time(0)));
    int coin = std::rand() % 2;

    std::cout << "Starting robotomization for " << getName() << "..." << std::endl;
    if (coin == 0) {
        std::cout << getName() << " has been successfully robotomized!" << std::endl;
    } else {
        std::cout << getName() << " failed the robotomization." << std::endl;
    }
}