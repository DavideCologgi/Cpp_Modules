/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:52:40 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/17 15:08:52 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error: Usage: " << argv[0] << "<file.txt>" << std::endl;
        return 1;
    }
    BitcoinExchange exc(argv[1], "data.csv");

    if (!exc.processFile()) {
        return 1;
    }
    return 0;
}
