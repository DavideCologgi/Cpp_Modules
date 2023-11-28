/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:23:25 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/28 12:01:16 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
    private:
        Brain*  brain;
    
    public:
        Dog();
        Dog(const Dog& other);
        ~Dog();

        void    makeSound() const;
        Dog*    clone() const;
};

#endif