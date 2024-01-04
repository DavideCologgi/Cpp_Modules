/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:19:59 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/04 12:25:53 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Intern {
    public:
        Intern();
        ~Intern();

        AForm*  makeForm(std::string form_name, std::string targ);
};

#endif