/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:42:09 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/16 12:10:25 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string p_name;
		Weapon		*p_weapon;
	
	public:
		HumanB(std::string name);
		~HumanB();

		void    attack();
		void	setWeapon(Weapon &weapon);
};

#endif