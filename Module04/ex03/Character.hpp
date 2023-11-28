/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:38:19 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/28 16:12:04 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter {
    private:
        std::string p_name;
        AMateria    *inventory[4];
        
    public:
        Character(std::string const &name);
        ~Character();
        
        std::string const   &getName() const;
        void                equip(AMateria *m);
        void                unequip(int idx);
        void                use(int idx, ICharacter &target);
};

#endif