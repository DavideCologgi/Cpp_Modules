/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:39:43 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/18 15:54:52 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char** argv) {
    RPN calc;

    if (argc != 2) {
        std::cerr << "Error: Usage: ./RPN <equation>" << std::endl;
        return 1;
    }
    calc.resolve(argv[1]);
    return 0;
}