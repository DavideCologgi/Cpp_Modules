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
        int arr2[] = {10, 20, 30, 50};
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