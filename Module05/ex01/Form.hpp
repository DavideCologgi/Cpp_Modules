/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:56:34 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/30 15:05:16 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class   Form {
	private:
		const std::string   name;
		bool                sign;
		const int           sign_grade;
		const int           exe_grade;
	
	public:
		class	GradeTooHighException() {};
		class	GradeTooLowException() {};

		const std::string	getName();
		bool				getSign();
		const int			getSignGrade();
		const int			getExeGrade();
		
		void				beSigned(Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat, const Form& form);

#endif