/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:57:17 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/30 15:05:33 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class   Bureaucrat {
	private:
		const std::string 	name;
		int					grade;

	public:
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw() {
					return ("Grade is too high");
				}
		};
		
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw() {
					return ("Grade is too low");
				}
		};
		
		Bureaucrat(const std::string& str, int n);
		~Bureaucrat();

		std::string 	getName() const;
		int				getGrade() const;
		void			gradeUp();
		void			gradeDown();
		void			signForm();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);


#endif