/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:03:25 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/16 15:28:45 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <stdexcept>
# include <vector>
# include <algorithm>
# include <limits>
# include <iostream>
# include <cstddef>

class Span {
    private:
        unsigned int        size;
        std::vector<int>    elements;
        
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        ~Span();

        Span&         operator=(const Span& other);
        void          addNumber(int n);
        void          addNumbers(const int* begin, const int* end);
        ptrdiff_t     shortestSpan();
        ptrdiff_t     longestSpan();
};

#endif