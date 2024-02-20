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

void                PmergeMe::populateVector(int n) {
	raw_vector.push_back(n);
}


void                PmergeMe::checkError() {
	std::vector<int>    check;
	bool has_duplicates = false;
	
	check = raw_vector;
	std::sort(check.begin(), check.end());
	if (check == raw_vector)
		throw std::invalid_argument("Error: Input already sorted!");
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

std::string         PmergeMe::displayVector(std::vector<int> vect) {
	std::string result;
	for (int num : vect) {
		result += std::to_string(num) + " ";
	}
	return result;
}

std::vector<int>    PmergeMe::splitVector() {
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

std::vector<int>    PmergeMe::binaryInsertionI(std::vector<int> raw, std::vector<int> final, int jacob) {
	int low = 0;
	int high = final.size() - 1;
	int size = raw.size();


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

std::vector<int>    PmergeMe::binaryInsertionII(std::vector<int> final, int val) {
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

void                PmergeMe::executeVector() {
	std::vector<int>	final;
	std::vector<int>	jacobsthal;
	int					odd_last;

	odd_last = -1;
	std::cout << "Before: " << displayVector(raw_vector) << std::endl;
	if (raw_vector.size() % 2 != 0) {
		odd_last = raw_vector.back();
		raw_vector.pop_back();
	}
	if (raw_vector.size() <= 4) {
		final = splitVector();
		std::sort(final.begin(), final.end());
		while (raw_vector.size() >= 1) {
			final = binaryInsertionII(final, raw_vector[0]);
			raw_vector.erase(raw_vector.begin());
		}
	} else {
		jacobsthal = calculateJacobsthalSequence(raw_vector.size() - 1);
		for (size_t i = 0; i < jacobsthal.size(); ++i) {
			jacobsthal[i] -= 1;
		}
		final = splitVector();
		std::sort(final.begin(), final.end());
		while (jacobsthal.size() >= 1) {
			final = binaryInsertionI(raw_vector, final, jacobsthal[0]);
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
	std::cout << "After: " << displayVector(raw_vector) << std::endl;
}

// Funzioni per liste

std::string         PmergeMe::displayList(std::deque<int> list) {
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

void                PmergeMe::populateList(int n) {
	raw_list.push_back(n);
}

std::deque<int>		PmergeMe::splitList() {
    std::deque<int> result;

    if (raw_list.size() < 2)
        return result;
    for (size_t i = 0; i < raw_list.size(); i += 2) {
        result.push_back(std::max(raw_list[i], raw_list[i + 1]));
    }
    for (size_t j = 0; j < result.size(); ++j) {
        int value = result[j];
        for (std::deque<int>::iterator it = raw_list.begin(); it != raw_list.end(); ++it) {
            if (*it == value) {
                raw_list.erase(it);
                break;
            }
        }
    }
    return result;
}

std::deque<int>		PmergeMe::calculateJacobsthalSequenceList(int n) {
	std::deque<int>		sequence = {0, 1};
	std::deque<int>		jacob;
	long unsigned int	z = 0;
	
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

std::deque<int>		PmergeMe::binaryInsertionIII(std::deque<int> raw, std::deque<int> final, int jacob) {
	int low = 0;
	int high = final.size() - 1;
	int size = raw.size();


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

std::deque<int>		PmergeMe::binaryInsertionIV(std::deque<int> final, int value) {
	int low = 0;
	int high = final.size() - 1;
	
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (final[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}
	final.insert(final.begin() + low, value);
	return final;
}

void				PmergeMe::executeList() {
	std::deque<int>	final;
	std::deque<int>	jacobsthal;
	int				odd_last;
	
	std::cout << "Before: " << displayList(raw_list) << std::endl;
	odd_last = -1;
	if (raw_list.size() % 2 != 0) {
		odd_last = raw_list.back();
		raw_list.pop_back();
	}
	if (raw_list.size() <= 4) {
		final = splitList();
		std::sort(final.begin(), final.end());
		while (raw_list.size() >= 1) {
			final = binaryInsertionIV(final, raw_list[0]);
			raw_list.erase(raw_list.begin());
		}
	} else {
		jacobsthal = calculateJacobsthalSequenceList(raw_list.size() - 1);
		for (size_t i = 0; i < jacobsthal.size(); ++i) {
			jacobsthal[i] -= 1;
		}
		final = splitList();
		std::sort(final.begin(), final.end());
		while (jacobsthal.size() >= 1) {
			final = binaryInsertionIII(raw_list, final, jacobsthal[0]);
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
	std::cout << "After: " << displayList(final) << std::endl;
	raw_list = final;
}
