/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:28:58 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/28 12:03:37 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain*  brain;
        
    public:
        Cat();
        Cat(const Cat& other);
        ~Cat();

        void    makeSound() const;
        Cat*    clone() const;
};

#endif
