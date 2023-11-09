/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:42:09 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/09 17:04:51 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		std::string weapon_b;
	
	public:
		HumanB(std::string name);
		~HumanB();

		void    attack();
		void	setWeapon(Weapon type);
};

#endif