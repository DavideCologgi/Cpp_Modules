/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:00:16 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/15 12:02:18 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T, typename Func>

void    iter(T* array, size_t len, Func fn) {
    for (size_t i = 0; i < len; ++i) {
        fn(array[i]);
    }
}

#endif