/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:19:59 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/04 16:23:48 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
    public:
        class FormNotFoundException : public std::exception {
			public:
				const char *what() const throw() {
					return ("form not found in the archive.");
				}
		};
        
        Intern();
        ~Intern();

        AForm*  makeForm(std::string form_name, std::string targ);
};

#endif