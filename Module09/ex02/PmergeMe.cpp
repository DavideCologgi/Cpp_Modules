/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:52:04 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/22 12:28:29 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}

PmergeMe::~PmergeMe() {}

PmergeMe&   PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        this->raw_vector = other.raw_vector;
    }
    return *this;
}

void                PmergeMe::populate(std::string num) {
    int n = atoi(num.c_str());
    raw_vector.push_back(n);
}

std::string         PmergeMe::display_vector(std::vector<int> vect) {
    std::string result;
    for (int num : vect) {
        result += std::to_string(num) + " ";
    }
    return result;
}

std::vector<int>    PmergeMe::split_vector() {
    std::vector<int> split;
    int i = 0;
    long unsigned int half = 0; 

    if (raw_vector.size() % 2 == 0) {
        while (half <= (raw_vector.size() / 2) + 1) {
            if (raw_vector[i] > raw_vector[i + 1]) {
                split.push_back(raw_vector[i]);
                raw_vector.erase(raw_vector.begin() + i);
            }
            else {
                split.push_back(raw_vector[i + 1]);
                raw_vector.erase(raw_vector.begin() + i + 1);
            }
            i++;
            half++;
        }
    } else {
        while (half <= (raw_vector.size() / 2)) {
            if (raw_vector[i] > raw_vector[i + 1]) {
                split.push_back(raw_vector[i]);
                raw_vector.erase(raw_vector.begin() + i);
            }
            else {
                split.push_back(raw_vector[i + 1]);
                raw_vector.erase(raw_vector.begin() + i + 1);
            }
            i++;
            half++;
        }
    }
    return split;
}

std::vector<int>    PmergeMe::calculateJacobsthalSequence(int n) {
    std::vector<int> sequence;
    sequence.push_back(0);
    sequence.push_back(1);
    
    for (int i = 2; i <= n; ++i) {
        sequence.push_back(sequence[i - 1] + 2 * sequence[i - 2]);
    }
    return sequence;
}

bool                compareDescending(int a, int b) {
    return a > b;
}

void                PmergeMe::execute_with_vector() {
    std::vector<int>    final;
    std::vector<int>    jacobsthal;
    //int                 index;

    std::cout << "Before: " << display_vector(raw_vector) << std::endl;
    jacobsthal = calculateJacobsthalSequence(raw_vector.size() / 2 - 1);
    std::cout << "Jacobsthal sequence: " << display_vector(jacobsthal) << std::endl;
    final = split_vector();
    std::cout << "Splitted final vector: " << display_vector(final) << std::endl;
    std::sort(final.begin(), final.end());
    if (raw_vector.size() % 2 == 0) {
        std::sort(raw_vector.begin(), raw_vector.end() - 1, compareDescending);
    } else {
        std::sort(raw_vector.begin(), raw_vector.end(), compareDescending);
    }
    std::cout << "Ordered input vector: " << display_vector(raw_vector) << std::endl;
    std::cout << "Ordered final vector: " << display_vector(final) << std::endl;
    //while (jacobsthal.size() > 0) {
    //    insert_number(final, raw_vector, jacobsthal[0]);

    //}
}