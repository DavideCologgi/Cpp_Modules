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

// Definizioni canoniche

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

// Funzioni per vettori

void                PmergeMe::populate_vect(std::string num) {
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
	std::vector<int> result;

	if (raw_vector.size() < 2)
		return result;
	for (size_t i = 0; i < raw_vector.size(); i += 2) {
		result.push_back(std::max(raw_vector[i], raw_vector[i + 1]));
	}
	for (size_t j = 0; j < result.size(); ++j) {
		int value = result[j];
		for (size_t k = 0; k < raw_vector.size(); ++k) {
			if (raw_vector[k] == value) {
				raw_vector.erase(raw_vector.begin() + k);
				break;
			}
		}
	}
	return result;
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
	return jacob;
}

std::vector<int>    PmergeMe::binary_insertionI(std::vector<int> raw, std::vector<int> final, int jacob) {
	int low = 0;
	int high = final.size() - 1;
	int size = raw_vector.size();


	while (jacob >= size) {
		jacob--;
	}
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (final[mid] < raw[jacob])
			low = mid + 1;
		else
			high = mid - 1;
	}
	final.insert(final.begin() + low, raw[jacob]);
	return final;
}

std::vector<int>    PmergeMe::binary_insertionII(std::vector<int> final, int val) {
	int low = 0;
	int high = final.size() - 1;
	
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (final[mid] < val)
			low = mid + 1;
		else
			high = mid - 1;
	}
	final.insert(final.begin() + low, val);
	return final;
}

void                PmergeMe::execute_with_vector() {
	std::vector<int>	final;
	std::vector<int>	jacobsthal;
	int					odd_last;

	odd_last = -1;
	std::cout << "Before: " << display_vector(raw_vector) << std::endl;
	if (raw_vector.size() % 2 != 0) {
		odd_last = raw_vector.back();
		raw_vector.pop_back();
	}
	if (raw_vector.size() <= 4) {
		final = split_vector();
		std::sort(final.begin(), final.end());
		while (raw_vector.size() >= 1) {
			final = binary_insertionII(final, raw_vector[0]);
			raw_vector.erase(raw_vector.begin());
		}
	} else {
		jacobsthal = calculateJacobsthalSequence(raw_vector.size() - 1);
		for (size_t i = 0; i < jacobsthal.size(); ++i) {
			jacobsthal[i] -= 1;
		}
		final = split_vector();
		std::sort(final.begin(), final.end());
		while (jacobsthal.size() >= 1) {
			final = binary_insertionI(raw_vector, final, jacobsthal[0]);
			jacobsthal.erase(jacobsthal.begin());
		}
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
	std::cout << "After: " << display_vector(raw_vector) << std::endl;
}

// Funzioni per liste

std::string         PmergeMe::display_list(std::deque<int> list) {
	std::stringstream ss;
	ss << "[";
	for (size_t i = 0; i < list.size(); ++i) {
		ss << list[i];
		if (i != list.size() - 1) {
			ss << ", ";
		}
	}
	ss << "]";
	return ss.str();
}

void                PmergeMe::populate_list(std::string num) {
	int n = atoi(num.c_str());

	raw_list.push_back(n);
}

void				PmergeMe::execute_with_list() {
	std::deque<int>	final;
	std::deque<int>	jacobsthal;
	int				odd_last;
	
	std::cout << "List: " << display_list(raw_list) << std::endl;
	odd_last = -1;
	if (raw_list.size() % 2 != 0) {
		odd_last = raw_list.back();
		raw_list.pop_back();
	}
	if (raw_list.size() <= 4) {
		final = split_list();
		std::sort(final.begin(), final.end());
		while (raw_list.size() >= 1) {
			final = binary_insertionIV(final, raw_list[0]);
			raw_list.erase(raw_list.begin());
		}
	} else {
		jacobsthal = calculateJacobsthalSequenceList(raw_list.size() - 1);
		for (size_t i = 0; i < jacobsthal.size(); ++i) {
			jacobsthal[i] -= 1;
		}
		final = split_list();
		std::sort(final.begin(), final.end());
		while (jacobsthal.size() >= 1) {
			final = binary_insertionIII(raw_list, final, jacobsthal[0]);
			jacobsthal.erase(jacobsthal.begin());
		}
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
	raw_list = final;
}
