/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:31:08 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/09 14:34:39 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <string>
# include <iostream>

class   Zombie {
	private:
		std::string  name;

	public:
		Zombie(std::string _name);
		~Zombie();
		
		void	announce();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif