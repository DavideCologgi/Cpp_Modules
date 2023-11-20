/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:05:27 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/20 12:51:20 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {
	Harl	harl;

	if (argc != 2) {
		std::cerr << "Invalid input: wrong number of parameters." << std::endl;
		return (1);
	}
	harl.complain(argv[1]);
	return (0);
}