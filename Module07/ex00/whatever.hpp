/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:31:54 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/15 10:58:07 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>

void swap(T &x, T &y) {
	T z;

	z = x;
	x = y;
	y = z;
}

template <typename T>

T min(T x, T y) {
	if (x <= y) {
		return x;
	} else
		return y; 
}

template <typename T>

T max(T x, T y) {
	if (x >= y) {
		return x;
	} else
		return y;
}

#endif