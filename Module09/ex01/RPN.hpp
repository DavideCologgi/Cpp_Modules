/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:40:07 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/18 16:27:09 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <algorithm>
# include <stack>
# include <cstdlib>

class RPN {
    private:
        std::stack<int> numbers;
        
    public: 
        RPN();
        RPN(const RPN& other);
        ~RPN();
        
        RPN&    operator=(const RPN& other);

        void    resolve(const std::string& equation);      
};

#endif