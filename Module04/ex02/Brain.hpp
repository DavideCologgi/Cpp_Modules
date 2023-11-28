/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:55:58 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/28 12:08:31 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class   Brain {
    private:
        std::string  ideas[100];
    
    public:
        Brain();
        ~Brain();
};

#endif