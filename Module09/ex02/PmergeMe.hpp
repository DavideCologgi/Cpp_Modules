/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:51:27 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/22 12:06:41 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>
# include <vector>
# include <algorithm>
# include <ctime>
# include <iostream>

class   PmergeMe {
    private:
        std::vector<int>    raw_vector;
        
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        ~PmergeMe();

        PmergeMe&   operator=(const PmergeMe& other);

        void                execute_with_vector();
        void                populate(std::string num);
        std::vector<int>    split_vector();
        std::vector<int>    calculateJacobsthalSequence(int n);
        std::string         display_vector(std::vector<int> vect);
};

#endif