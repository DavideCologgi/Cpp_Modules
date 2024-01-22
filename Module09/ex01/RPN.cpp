/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:39:57 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/22 11:19:41 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) {
    *this = other;
}

RPN::~RPN() {}

RPN&    RPN::operator=(const RPN& other) {
    if (this != &other) {
        this->numbers = other.numbers;
    }
    return *this;
}

bool    RPN::isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    else
        return false;
}

void    RPN::resolve(const std::string& equation) {
    std::string operators;
    std::string valid_char = " +-/*0123456789";
    std::stack<int> result;
    
    // Controllo validitá input
    for (char c : equation) {
        if (valid_char.find(c) == std::string::npos) {
            std::cerr << "Error" << std::endl;
            return;
        }
    }
    // Trova e salva gli operatori
    for (char x : equation) {
        if (isOperator(x)) {
            if (numbers.size() <= 1) {
                std::cerr << "Error: Usage: ./RPN '<n1> <n2> <operator>'" << std::endl;
                return;
            }
            operators += x;
        } else if (x != ' ') {
            int n = static_cast<int>(x - '0');
            numbers.push(n);
        }
    }
    // Controllo correttezza espressione e caso identitá
    if (operators.length() != numbers.size() - 1) {
        std::cerr << "Error: invalid expression format." << std::endl;
        return;
    } else if (operators.length() == 0) {
        std::cout << numbers.top() << std::endl;
        return;
    }
    // Algoritmo di risoluzione
    for (char c : equation) {
        if (!isOperator(c) && c != ' ') {
            int n = static_cast<int>(c - '0');
            result.push(n);
        } else if (isOperator(c)) {
            int tmp2 = result.top();
            result.pop();
            int tmp1 = result.top();
            result.pop();
            switch (c) {
                case '+':
                    result.push(tmp1 + tmp2);
                    break;
                case '-':
                    result.push(tmp1 - tmp2);
                    break;
                case '*':
                    result.push(tmp1 * tmp2);
                    break;
                case '/':
                    result.push(tmp1 / tmp2);
                    break;
                default:
                    break;
            }
        } 
    }
    std::cout << result.top() << std::endl;
}