/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:34:13 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/28 17:11:24 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class   IMateriaSource {
	public:
		virtual ~IMateriaSource();
		
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif