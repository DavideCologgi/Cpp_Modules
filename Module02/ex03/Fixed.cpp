/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:22:08 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/22 14:55:25 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Costruttori e distruttori
Fixed::Fixed() : value(0) {}

Fixed::Fixed(const int num) : value(num << bits) {}

Fixed::Fixed(const float f_num) : value(roundf(f_num * (1 << bits))) {}

Fixed::Fixed(const Fixed& other) : value(other.value) {}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		value = other.value;
	}
	return (*this);
}

Fixed::~Fixed() {}

// Funzioni generali
int		Fixed::getRawBits() const {
	return (value);
}

void	Fixed::setRawBits(int const raw) {
	value = raw;
}

float   Fixed::toFloat() const {
    return ((static_cast<float>(value)) / (static_cast<float>(1 << bits)));
}

int     Fixed::toInt() const {
    return (value >> bits);
}


// Operatori di comparazione
bool 	Fixed::operator>(const Fixed& other) const {
	return (value > other.value);
}

bool 	Fixed::operator<(const Fixed& other) const {
	return (value < other.value);
}

bool 	Fixed::operator>=(const Fixed& other) const {
	return (value >= other.value);
}

bool 	Fixed::operator<=(const Fixed& other) const {
	return (value <= other.value);
}

bool 	Fixed::operator==(const Fixed& other) const {
	return (value == other.value);
}

bool 	Fixed::operator!=(const Fixed& other) const {
	return (value != other.value);
}

// Operatori aritmetici
Fixed 	Fixed::operator+(const Fixed& other) const {
	Fixed	result;
	result.value = value + other.value;
	return (result);
}

Fixed 	Fixed::operator-(const Fixed& other) const {
	Fixed	result;
	result.value = value - other.value;
	return (result);
}

Fixed 	Fixed::operator*(const Fixed& other) const {
	Fixed	result;
	result.value = static_cast<int>((static_cast<long long>(value) * other.value) >> bits);
	return (result);
}

Fixed 	Fixed::operator/(const Fixed& other) const {
	Fixed	result;
	result.value = static_cast<int>((static_cast<long long>(value) << bits) / other.value);
	return (result);
}

// Operatori di incremento e decremento
Fixed&	Fixed::operator++() {
	++value;
	return (*this);
}

Fixed&	Fixed::operator--() {
	--value;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp(*this);
	++(*this);
	return (tmp);
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp(*this);
	--(*this);
	return (tmp);
}

// Funzioni di minimo e massimo
Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	if (a < b) {
		return (a);
	} else {
		return (b);
	}
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	if (a < b) {
		return (a);
	} else {
		return (b);
	}
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	if (a > b) {
		return (a);
	} else {
		return (b);
	}
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	if (a > b) {
		return (a);
	} else {
		return (b);
	}
}

// Overload operatore di inserzione
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return (out);
}