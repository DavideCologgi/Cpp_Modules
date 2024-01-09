/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:00:49 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/09 14:31:13 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    *this = other; 
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void) other;
    return (*this);
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& str) {
    std::string specificValues[6] = {
        "-inff",
        "+inff",
        "nanf",
        "nan",
        "-inf",
        "+inf"
    };
    std::string s = "";
    int         n = 0;
    float       f = 0;
    double      d = 0;

    // Check if input is a single char
    switch(str.size()) {
        case 1:
            if (std::isprint(str[0]) && !std::isdigit(str[0])) {
                s = str[0];
                std::cout << "char: " << s << std::endl;
                std::cout << "int: " << static_cast<int>(s[0]) << std::endl;
                std::cout << "float: " << static_cast<float>(s[0]) << ".0f" << std::endl;
                std::cout << "double: " << static_cast<double>(s[0]) << ".0" << std::endl;
                return ;
           }
           break ;
        default:
            break ;
    }

    n = std::atoi(str.c_str());

    // Check if input is a float
    switch (str[str.length() - 1]) {
        case 'f':
            f = std::atof(str.c_str());
            d = static_cast<double>(f);
            break ;
        default:
            d = std::atof(str.c_str());
            f = static_cast<float>(d);
            break ;
    }

    // Check if a specific value
    for (int i = 0; i < 6; ++i) {
        if (str == specificValues[i]) {
            s = "impossible";
            break ;
        }
    }

    // Convert int to char
    if (s == "" && std::isprint(n)) {
        s = "'";
        s += static_cast<char>(n);
        s += "'";
    } else if (s == "") {
        s = "Non displayable";
    }
    
    // Print char
    std::cout << "char: " << s << std::endl;

    //Print int
    switch (s[0]) {
        case 'i':
            std::cout << "int: impossible" << std::endl;
            break ;
        default:
            std::cout << "int: " << n << std::endl;
            break ; 
    }

    // Print float and double
    if (s == "impossible" && f == 0) {
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    } else {
        if (s != "impossible" && f - static_cast<int>(f) == 0){
            std::cout << "float: " << f << ".0f" << std::endl;
            std::cout << "double: " << d << ".0" << std::endl;
        } else {
            std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
        }
    }
}