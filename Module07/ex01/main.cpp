/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:00:03 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/15 11:57:24 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T>
void printElement(const T& element) {
    std::cout << element << " ";
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArraySize = sizeof(intArray) / sizeof(int);

    std::cout << "Iterating over integers: ";
    iter(intArray, intArraySize, printElement<int>);
    std::cout << "\n";

    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleArraySize = sizeof(doubleArray) / sizeof(double);

    std::cout << "Iterating over doubles: ";
    iter(doubleArray, doubleArraySize, printElement<double>);
    std::cout << "\n";

    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    size_t charArraySize = sizeof(charArray) / sizeof(char);

    std::cout << "Iterating over characters: ";
    iter(charArray, charArraySize, printElement<char>);
    std::cout << "\n";

    return 0;
}