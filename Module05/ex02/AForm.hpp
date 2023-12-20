/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:49:41 by dcologgi          #+#    #+#             */
/*   Updated: 2023/12/20 15:53:29 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class	Bureaucrat;

class   AForm {
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

		AForm();
		AForm(const std::string& form, int grade, int exe);
		virtual ~AForm();
		
		std::string	getName() const;
		bool		getSign() const;
		int			getSignGrade() const;
		int			getExeGrade() const;
		void		setSign(bool firmed);
		
		virtual void	beSigned(Bureaucrat& bureaucrat) const = 0;
		virtual void	execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif