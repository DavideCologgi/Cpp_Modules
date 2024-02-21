/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:20:32 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/16 10:58:42 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
    try {
        int arr[] = {1, 2, 3, 2, 5};
        int len = sizeof(arr) / sizeof(arr[0]);

        std::cout << "First array: ";
        for (int i = 0; i < len; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        int arr2[] = {10, 20, 30, 50};
        int len2 = sizeof(arr2) / sizeof(arr2[0]);

        std::cout << "Second array: ";
        for (int j = 0; j < len2; ++j) {
            std::cout << arr2[j] << " ";
        }
        std::cout << std::endl;

        int value = 2;
        std::vector<int> vect1(arr, arr + sizeof(arr) / sizeof(arr[0]));
        std::list<int> list1(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));

        std::vector<int>::iterator result = easyfind(vect1, value);
        std::cout << "Parameter found in position: "
            << std::distance(vect1.begin(), result) << std::endl;
                
        std::list<int>::iterator lresult = easyfind(list1, value);
        std::cout << "Parameter found in position: "
            << std::distance(list1.begin(), lresult) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}