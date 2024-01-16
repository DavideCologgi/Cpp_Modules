/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:20:23 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/16 10:44:24 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <stdexcept>
# include <algorithm>

template <typename T>

typename T::iterator easyfind(T& container, int x) {
    typename T::iterator it = std::find(container.begin(), container.end(), x);
    
    if (it != container.end()) {
        return it;
    } else {
        throw std::runtime_error("Parameter not found.");
    }
}

#endif