/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:47:04 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/09 15:42:08 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HORDE_H
# define HORDE_H
# include <iostream>

class Zombie
{
	private:
		std::string name;
		
	public:
		Zombie();
		
		void    announce();
		void	setName(std::string name);
		
		~Zombie();
};

Zombie*	zombieHorde(int n, std::string name);

#endif