/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:06:39 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/16 15:51:05 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : size(0) {}

Span::Span(unsigned int N) : size(N) {}

Span::~Span() {}

Span::Span(const Span& other) : size(other.size) {
    *this = other;
}

Span&   Span::operator=(const Span& other) {
    (void) other;
    return *this;
}

void    Span::addNumber(int n) {
    if (elements.size() >= size) {
        throw std::out_of_range("span is full!");
    }
    elements.push_back(n);
}

std::ptrdiff_t    Span::shortestSpan() {
    if (elements.size() < 2) {
        throw std::logic_error("not enough elements to calculate!");
    }
    
    std::vector<int> sorted = elements;
    std::sort(sorted.begin(), sorted.end());
    
    std::ptrdiff_t minSpan = std::numeric_limits<std::ptrdiff_t>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        std::ptrdiff_t span = sorted[i] - sorted[i - 1];
        minSpan = std::min(minSpan, span);
    }
    return minSpan;
}

ptrdiff_t    Span::longestSpan() {
    if (elements.size() <= 1) {
        throw std::logic_error("not enough elements to calculate!");
    }
    std::vector<int>::iterator max = std::max_element(elements.begin(), elements.end());
    std::vector<int>::iterator min = std::min_element(elements.begin(), elements.end());
    std::ptrdiff_t maxSpan = std::abs(*max - *min);
    return maxSpan;
}