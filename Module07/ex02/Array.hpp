/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:05:22 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/15 14:25:48 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>

template <typename T>
class Array {
    private:
        T*              data;
        unsigned int    len;

    public:
        Array() : data(NULL), len(0) {}
        
        Array(unsigned int n) : len(n) {
            data = new T[len]();
        }
        
        Array(const Array& other) : len(other.len) {
            data = new T[len];
            for (unsigned int i = 0; i < len; ++i) {
            data[i] = other.data[i];
            }
        }
        
        ~Array() {
            delete[] data;
        }

        T&              operator[](unsigned int index) {
            if (index >= len) {
                throw std::out_of_range("Error: Index out of range!");
            }
            return data[index];
        }
        
        Array&          operator=(const Array& other) {
            if (this != &other) {
                delete[] data;
                len = other.len;
                data = new T[len];
                for (unsigned int i = 0; i < len; ++i){
                    data[i] = other.data[i];
                }
            }
            return *this;
        }
        
        unsigned int    size() const {
            return len;
        }
        
};

#endif