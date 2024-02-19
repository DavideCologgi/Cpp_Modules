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
#include <chrono>
#include <sstream>

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
            throw std::invalid_argument("Error: No stack to order as input!");
        } else {
            if (argc == 2 && atoi(argv[1])) {
                throw std::invalid_argument("Error: Input must have at least 2 numbers!");
            } else {
                PmergeMe    algorithm;
                int i = 1;
                
                typedef std::chrono::high_resolution_clock Clock;
                typedef std::chrono::microseconds Microseconds;

                Clock::time_point start;
                Clock::time_point end;

                start = Clock::now();
                while (i < argc) {
                    algorithm.populate(argv[i]);
                    i++;
                }
                algorithm.check_error();
                algorithm.execute_with_vector();
                end = Clock::now();

                Microseconds duration = std::chrono::duration_cast<Microseconds>(end - start);
                std::cout << "Time to process a range of " << argc - 1 << " elements with vectors: " << duration.count() << " ms" << std::endl;
            }
            return 0;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}