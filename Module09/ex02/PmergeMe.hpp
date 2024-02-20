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
# include <sstream>

class   PmergeMe {
	private:
		std::vector<int>    raw_vector;
		std::deque<int>     raw_list;
		
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		~PmergeMe();

		PmergeMe&   operator=(const PmergeMe& other);

		// Funzioni per vettori

		void                execute_with_vector();
		void                populate_vect(std::string num);
		void                check_error();
		std::vector<int>    split_vector();
		std::vector<int>    calculateJacobsthalSequence(int n);
		std::vector<int>    binary_insertionI(std::vector<int> input, std::vector<int> res, int index);
		std::vector<int>    binary_insertionII(std::vector<int> final, int val);
		std::string         display_vector(std::vector<int> vect);

		// Funzioni per liste

		void                execute_with_list();
		void                populate_list(std::string num);
		std::deque<int>     split_list();
		std::deque<int>		calculateJacobsthalSequenceList(int n);
		std::deque<int>     binary_insertionIII(std::deque<int> input, std::deque<int> res, int index);
		std::deque<int>     binary_insertionIV(std::deque<int> final, int val);
		std::string         display_list(std::deque<int> list);
};

#endif