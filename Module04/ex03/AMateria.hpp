/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:05:34 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/28 16:11:15 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

class	ICharacter;

class	AMateria {
	protected:
		std::string p_type;
		
	public:
		AMateria(std::string const & type);
		virtual ~AMateria();

		std::string const & getType() const;
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

#endif