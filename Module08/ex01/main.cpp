/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:03:10 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/16 15:52:31 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
	try {
		Span	sp = Span(5);
		
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		//sp.addNumber(10);
		
		std::cout << "Shortest span is: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span is: " << sp.longestSpan() << std::endl;

		Span	sp2 = Span(10);
		int 	arr[] = {6, 3, 17, 9, 11};
    	
		sp2.addNumbers(arr, arr + sizeof(arr) / sizeof(arr[0]));
		std::cout << "Shortest span is: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span is: " << sp2.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
