/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:52:40 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/18 10:48:09 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
    BitcoinExchange exc;
    
    if (argc != 2) {
        std::cerr << "Error: Usage: " << argv[0] << " <file.txt>" << std::endl;
        return 1;
    }
    exc.processFile(argv[1]);
    return 0;
}
