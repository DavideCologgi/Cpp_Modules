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
#include <cstdio>
#include <cstdlib>
#include <cstring>

void checkArgv(const char *argv) {
    int i = 0;
    while (argv[i]) {
        if (argv[i] < '0' || argv[i] > '9') {
            throw std::invalid_argument("Error: Only positive numbers allowed!");
        }
        i++;
    }
}

int main(int argc, char **argv) {
    try {
        if (argc == 1) {
            throw std::invalid_argument("Error: No stack to order as input!");
        }

        PmergeMe algorithm;
        int i = 1;

        typedef std::chrono::high_resolution_clock Clock;
        typedef std::chrono::microseconds Microseconds;

        Clock::time_point start;
        Clock::time_point end;

        start = Clock::now();

        if (strcmp(argv[1], "shuf") == 0) {
            if (argc != 3) {
                throw std::invalid_argument("Error: Usage: ./PmergeMe shuf <options>\n");
            }
            FILE *fp = popen(argv[2], "r");
            if (fp == nullptr) {
                throw std::invalid_argument("Error executing command");
            }
            int value;
            while (fscanf(fp, "%d", &value) == 1) {
                algorithm.populateVector(value);
            }
            pclose(fp);
        } else {
            while (i < argc) {
                checkArgv(argv[i]);
                algorithm.populateVector(std::atoi(argv[i]));
                algorithm.populateList(std::atoi(argv[i]));
                i++;
            }
        }

        algorithm.checkError();
        std::cout << "Execution with vector container:" << std::endl << std::endl;
        algorithm.executeVector();
        end = Clock::now();

        Microseconds duration = std::chrono::duration_cast<Microseconds>(end - start);
        std::cout << "Time to process a range of " << argc - 1 << " elements with vectors: " << duration.count() << " ms" << std::endl << std::endl;
        std::cout << "------------------------------------------------------------------" << std::endl << std::endl;

        start = Clock::now();
        std::cout << "Execution with deque container:" << std::endl << std::endl;
        algorithm.executeList();
        end = Clock::now();

        Microseconds durationDeque = std::chrono::duration_cast<Microseconds>(end - start);
        std::cout << "Time to process a range of " << argc - 1 << " elements with deque: " << durationDeque.count() << " ms" << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}