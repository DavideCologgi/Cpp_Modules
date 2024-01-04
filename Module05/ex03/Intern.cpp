/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:27:01 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/04 16:31:48 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

AForm* Intern::makeForm(std::string form_name, std::string targ) {
    std::string archive[] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };
    AForm*      forms[] = {
        new RobotomyRequestForm(targ),
        new PresidentialPardonForm(targ),
        new ShrubberyCreationForm(targ)
    };
    AForm*      form_found;
    
    for (int i(0); i < 3; i++) {
        if (form_name == archive[i]) {
            std::cout << "Intern creates " << form_name << std::endl;
            form_found = forms[i];
            for (int j(0); j < 3; j++) {
                if (j != i) {
                    delete forms[j];
                }
            }
            return form_found;
        }
    }
    for (int i(0); i < 3; i++) {
        delete forms[i];
    }
    throw FormNotFoundException();
    return NULL;
}