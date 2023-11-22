/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:18:47 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/22 13:44:05 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class   Point {
    private:
        const Fixed x;
        const Fixed y;

        Point(const Fixed& xValue, const Fixed& yValue);
    
    public:
        Point();
        Point(const float z, const float w);
        Point(const Point& other);
        Point& operator=(const Point& other);
        ~Point();
        
        Fixed   getX() const;
        Fixed   getY() const;
};

bool    bsp(Point const a, Point const b, Point const c, Point const point);

#endif