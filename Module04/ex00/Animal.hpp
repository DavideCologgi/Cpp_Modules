/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:32:28 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/27 10:48:47 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

class Animal {
	protected:
		std::string	type;
		
	public:
		Animal();
		~Animal();
	
		void	makeSound();
		std::string	getType() const;
};

#endif