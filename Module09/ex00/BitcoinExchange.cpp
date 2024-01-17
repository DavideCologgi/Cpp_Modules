/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:53:00 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/17 15:25:40 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const char* txt, const char* db)
    : txtFile(txt), dbFile(db) {}

BitcoinExchange::~BitcoinExchange() {
    if (txtFile) {
        txtFile.close();
        delete txtFile;
    }
    if (dbFile) {
        dbFile.close();
        delete dbFile;
    }
}

BitcoinExchange&    BitcoinExchange::operator=(const BitcoinExchange& other) {
    (void) other;
    return *this;
}

bool    BitcoinExchange::isValidValue(const std::string& value) {
    std::istringstream  iss(value);
    double              number;
    
    iss >> number >> std::ws;
    return (iss.eof() && number > 0 && number <= 1000);
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        txtFile.close();
        dbFile.close();

        txtFile.open(other.txtFile.str().c_str());
        dbFile.open(other.dbFile.str().c_str());

        if (!txtFile.is_open() || !dbFile.is_open()) {
            std::cerr << "Error: could not open files." << std::endl;
            return *this;
        }
        dataMap = other.dataMap;
    }
    return *this;
}

bool    BitcoinExchange::processFile() {
    if (!txtFile.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return false;
    } else if (!dbFile.is_open()) {
        std::cerr << "Error: could not open database." << std::endl;
        return false;
    }

    std::string line;
    std::getline(txtFile, line);
    
    while (std::getline(txtFile, line)) {
        std::istringstream iss(line);
        std::string date, separator, value;

        if (iss >> date >> separator >> value && separator == "|") {
            if (isValidValue(value)) {
                try {
                    double numericValue = std::stod(value);
                    dataMap[date] = numericValue;
                    std::cout << date << " => " << value << std::endl;
                } catch (std::invalid_argument&) {
                    std::cerr << "Error: invalid value." << std::endl;
                } catch (std::out_of_range&) {
                    std::cerr << "Error: too large a number." << std::endl;
                }
            } else {
                std::cerr << "Error: not a positive number." << std::endl;
            }
        } else {
            if (!line.empty()) {
                std::cerr << "Error: bad input => " << line << std::endl;
            }
        }
    }
    txtFile.close();
    dbFile.close();
    return true;
}