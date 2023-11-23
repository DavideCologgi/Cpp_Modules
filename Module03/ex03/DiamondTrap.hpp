/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:37:50 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/23 11:15:29 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class   DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string	name;
	
	public:
		DiamondTrap(const std::string& newName);
		~DiamondTrap();

		void	whoAmI();
};

#endif