/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:41:04 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/04 11:44:07 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    private:
        std::string target;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string targ);
        ~PresidentialPardonForm();

        void    execute(const Bureaucrat& executor) const;
};

#endif