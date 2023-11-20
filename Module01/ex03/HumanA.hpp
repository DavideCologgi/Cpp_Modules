/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:41:38 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/16 12:00:26 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string p_name;
		Weapon	&p_weapon;
	
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();

		void    attack();
		void	setWeapon(Weapon weapon);
};

#endif