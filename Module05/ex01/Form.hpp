/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:56:34 by dcologgi          #+#    #+#             */
/*   Updated: 2023/12/11 12:33:30 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class	Bureaucrat;

class   Form {
	private:
		const std::string   name;
		bool                sign;
		const int           sign_grade;
		const int           exe_grade;
	
	public:
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw() {
					return ("SignGrade is too high");
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw() {
					return ("SignGrade is too low");
				}
		};

		Form(const std::string& form, int grade, int exe);
		~Form();
		
		std::string	getName() const;
		bool		getSign() const;
		int			getSignGrade() const;
		int			getExeGrade() const;
		void		setSign(bool firmed);
		
		void		beSigned(Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif