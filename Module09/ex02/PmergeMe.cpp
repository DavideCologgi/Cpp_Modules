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

void                PmergeMe::check_error() {
    std::vector<int>    check;
    bool has_duplicates = false;
    
    check = raw_vector;
    std::sort(check.begin(), check.end());
    if (check == raw_vector)
        throw std::invalid_argument("Error: input already sorted!");
    for (size_t i = 0; i < raw_vector.size(); ++i) {
        for (size_t j = i + 1; j < raw_vector.size(); ++j) {
            if (raw_vector[i] == raw_vector[j]) {
                has_duplicates = true;
                break;
            }
        }
        if (has_duplicates) {
            throw std::invalid_argument("Error: No duplicates allowed!");
        }
    }
    for (size_t i = 0; i < raw_vector.size(); ++i) {
        if (raw_vector[i] <= 0) {
            throw std::invalid_argument("Error: Only positive numbers allowed!" );
            break;
        }
    }
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
    std::vector<int>    sequence = {0, 1};
    std::vector<int>    jacob;
    long unsigned int   z = 0;
    
    if (n <= 1)
        return {sequence.begin(), sequence.begin() + n + 1};
    for (int i = 2; i <= n; ++i) {
        sequence.push_back(sequence[i - 1] + 2 * sequence[i - 2]);
    }
    sequence.erase(sequence.begin());
    sequence.erase(sequence.begin());
    jacob.push_back(sequence[z]);
    while (z < sequence.size()) {
        jacob.push_back(sequence[z + 1]);
        int y = sequence[z + 1];
        while (y > sequence[z] + 1) {
            jacob.push_back(y - 1);
            y--;
        }
        z++;
    }
    while (jacob.size() != ((sequence.size() + 2) / 2)) {
        jacob.pop_back();
    }
    std::cout << "Jacob: " << display_vector(jacob) << std::endl;
    return jacob;
}

std::vector<int>    PmergeMe::binary_insertion(std::vector<int> raw, std::vector<int> final, int jacob) {
    int low = 0;
    int high = final.size() - 1;
    
    raw.insert(raw.begin(), 0);
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (final[mid] < raw[jacob])
            low = mid + 1;
        else
            high = mid - 1;
    }
    final.insert(final.begin() + low, raw[jacob]);
    raw.erase(raw.begin());
    return final;
}

void                PmergeMe::execute_with_vector() {
    std::vector<int>    final;
    std::vector<int>    jacobsthal;

    odd_last = -1;
    std::cout << "Before: " << display_vector(raw_vector) << std::endl;
    if (raw_vector.size() <= 5) {
        std::sort(raw_vector.begin(), raw_vector.end());
    } else {
        if (raw_vector.size() % 2 != 0) {
            odd_last = raw_vector.back();
            raw_vector.pop_back();
        }
        jacobsthal = calculateJacobsthalSequence(raw_vector.size() - 1);
        final = split_vector();
        std::sort(final.begin(), final.end());
        while (jacobsthal.size() >= 1) {
            final = binary_insertion(raw_vector, final, jacobsthal[0]);
            jacobsthal.erase(jacobsthal.begin());
        }
        if (odd_last >= 0) {
            for (size_t i = 0; i < final.size(); ++i) {
                if (final[i] > odd_last) {
                    final.insert(final.begin() + i, odd_last);
                    odd_last = -1;
                    break;
                }
            }
            if (odd_last >= 0) {
                final.push_back(odd_last);
            }
        }
        raw_vector = final;
    }
    std::cout << "After: " << display_vector(raw_vector) << std::endl;
}