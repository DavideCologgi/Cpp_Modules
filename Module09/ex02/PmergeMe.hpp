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

		void                executeVector();
		void                populateVector(int n);
		void                checkError();
		std::vector<int>    splitVector();
		std::vector<int>    calculateJacobsthalSequence(int n);
		std::vector<int>    binaryInsertionI(std::vector<int> input, std::vector<int> res, int index);
		std::vector<int>    binaryInsertionII(std::vector<int> final, int val);
		std::string         displayVector(std::vector<int> vect);

		// Funzioni per liste

		void                executeList();
		void                populateList(int n);
		std::deque<int>     splitList();
		std::deque<int>		calculateJacobsthalSequenceList(int n);
		std::deque<int>     binaryInsertionIII(std::deque<int> input, std::deque<int> res, int index);
		std::deque<int>     binaryInsertionIV(std::deque<int> final, int val);
		std::string         displayList(std::deque<int> list);
};

#endif