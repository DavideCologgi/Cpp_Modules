/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:53:42 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/17 10:01:16 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        class iterator {
            public:
                explicit iterator(typename std::stack<T>::container_type::iterator it) : current(it) {}

                bool        operator!=(const iterator& other) const {
                    return (current != other.current);
                }

                T&          operator*() const {
                    return *current;
                }

                iterator&   operator++() {
                    ++current;
                    return *this;
                }

                iterator&   operator--() {
                    --current;
                    return *this;
                }

            private:
                typename std::stack<T>::container_type::iterator current;
        };

        iterator    begin() {
            return iterator(this->c.begin());
        }

        iterator    end() {
            return iterator(this->c.end());
        }
};

#endif