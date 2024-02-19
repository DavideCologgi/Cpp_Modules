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
        int                 odd_last;
        
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        ~PmergeMe();

        PmergeMe&   operator=(const PmergeMe& other);

        void                execute_with_vector();
        void                populate(std::string num);
        void                check_error();
        std::vector<int>    split_vector();
        std::vector<int>    calculateJacobsthalSequence(int n);
        std::vector<int>    binary_insertion(std::vector<int> input, std::vector<int> res, int index);
        std::string         display_vector(std::vector<int> vect);
};

#endif