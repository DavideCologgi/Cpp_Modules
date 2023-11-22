/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:25:48 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/22 14:54:56 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(const Fixed& xValue, const Fixed& yValue) : x(xValue), y(yValue) {
	std::cout << "Private costructor called" << std::endl;
}

Point::Point() : x(0), y(0) {
	std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float z, const float w) : x(z), y(w) {
	std::cout << "Specified constructor called" << std::endl;
}

Point::Point(const Point& other) : x(other.x), y(other.y) {
	std::cout << "Copy constructor called" << std::endl;
}

Point& Point::operator=(const Point& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		*this = Point(other.x, other.y);
	}
	return (*this);
}

Point::~Point() {
	std::cout << "Destructor called" << std::endl;
}

Fixed   Point::getX() const {
	return (x);
}

Fixed   Point::getY() const {
	return (y);
}