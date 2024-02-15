/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:51:12 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/22 12:05:21 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

void    check_input(char* str) {
    int i = 0;

    while (str[i]) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != ' ') {
            throw std::invalid_argument("Error: insert only positive numbers as input!");
        }
        i++;
    }
    return;
}

int main(int argc, char **argv) {
    try
    {
        if (argc == 1) {
            throw std::invalid_argument("Error: no stack to order as input!");
        }
        else {
            PmergeMe    algorithm;
            int i = 1;

            while (i < argc) {
                check_input(argv[i]);
                algorithm.populate(argv[i]);
                i++;
            }
            algorithm.execute_with_vector();
        }
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}