/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:01:50 by dcologgi          #+#    #+#             */
/*   Updated: 2023/12/20 15:57:39 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		const std::string	target;

	public:
		ShrubberyCreationForm(const std::string target_name);
		~ShrubberyCreationForm();

		void	setSignGrade(int sign);
		void	setExeGrade(int exe);
		void	execute(Bureaucrat const & executor) const;
		void	beSigned(Bureaucrat& bureaucrat);
};

#endif