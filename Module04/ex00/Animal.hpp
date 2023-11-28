/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:32:28 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/28 10:02:49 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal {
	protected:
		std::string	type;
		
	public:
		Animal();
		virtual ~Animal();
	
		virtual void		makeSound() const;
		const std::string&	getType() const;
};

#endif