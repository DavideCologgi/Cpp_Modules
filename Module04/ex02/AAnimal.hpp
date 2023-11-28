/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:32:28 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/28 14:50:40 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal {
	protected:
		std::string	type;
		
	public:
		virtual ~AAnimal();
	
		virtual void		makeSound() const = 0;
		const std::string&	getType() const;
		virtual	AAnimal*	clone() const = 0;
		static AAnimal*		createAnimal();
};

#endif