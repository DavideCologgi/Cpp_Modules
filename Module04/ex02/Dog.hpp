/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:23:25 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/28 14:07:47 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {
    private:
        Brain*  brain;
    
    public:
        Dog();
        Dog(const Dog& other);
        ~Dog();

        void        makeSound() const;
        static Dog* createDog();
        Dog*        clone() const;
};

#endif