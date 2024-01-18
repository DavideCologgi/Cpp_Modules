/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:39:57 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/18 17:28:08 by dcologgi         ###   ########.fr       */
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

void    RPN::resolve(const std::string& equation) {
    std::string operators;
    std::string valid_char = " +-/*0123456789";
    std::stack<int> result;
    
    for (char c : equation) {
        if (valid_char.find(c) == std::string::npos) {
            std::cerr << "Error" << std::endl;
            return;
        }
    }
    for (char x : equation) {
        int num = static_cast<int>(x - '0');
        if (x != ' ' && !(num >= 0 && num <= 9))
            operators += x;
    }
    std::string reverse = equation;
    std::reverse(reverse.begin(), reverse.end());
    for (char n : reverse) {
        int num = static_cast<int>(n - '0');
        if (num >= 0 && num <= 9) {
            numbers.push(num); 
        }
    }
    if (operators.length() != numbers.size() - 1) {
        std::cerr << "Error: invalid expression format" << std::endl;
        return;
    }
    result.push(numbers.top());
    numbers.pop();
    for (char c : operators) {
        int tmp = result.top();
        switch (c) {
            case '+':
                result.push(tmp + numbers.top());
                numbers.pop();
                break;
            case '-':
                result.push(tmp - numbers.top());
                numbers.pop();
                break;
            case '*':
                result.push(tmp * numbers.top());
                numbers.pop();
                break;
            case '/':
                result.push(tmp / numbers.top());
                numbers.pop();
                break;
            default:
                break;
        }
    }
    std::cout << result.top() << std::endl;
}