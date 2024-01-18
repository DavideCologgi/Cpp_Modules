/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:53:00 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/18 15:33:20 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    std::ifstream   dbFile("data.csv");
    std::string     line;

    std::getline(dbFile, line);
    while (std::getline(dbFile, line)) {
        size_t      separator;
        std::string date;
        std::string rate;
        
        separator = line.find(',');
        date = line.substr(0, separator);
        rate = line.substr(separator + 1, line.length());

        dataMap[date] = rate;
    }
    dbFile.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
        *this = other;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange&    BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        dataMap = other.dataMap;
    }
    return *this;
}

void    BitcoinExchange::processFile(const std::string& fileName) {

    std::ifstream   file(fileName);
    
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "Error: empty file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);
    
    if (line != "date | value") {
        std::cerr << "Error: invalid file format: <date | value>" << std::endl;
    }
    
    while (std::getline(file, line)) {
        size_t  separator;
        std::string date, value;

        separator = line.find('|');
        if (separator == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        date = line.substr(0, separator - 1);
        value = line.substr(separator + 1);

        if (!checkDate(date)) {
            std::cerr << "Error: invalid date => " << date << std::endl;
            continue;
        }
        if (checkValue(value) == -1) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        } else if (checkValue(value) == 1001) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        
        std::map<std::string, std::string>::iterator  it;
        std::string prev_date;
        
        prev_date = date;
        it = dataMap.find(date);   
        while (it == dataMap.end() && !prev_date.empty()) {
            std::string& current = prev_date;
            prev_date = getPreviousDate(current);
            it = dataMap.find(prev_date);
        }
        std::cout << date << "=>" << value << " = " << std::stod(it->second) * std::stod(value) << std::endl;
    }
    file.close();
}

bool    BitcoinExchange::checkDate(std::string& date) {
    std::istringstream ss(date);
    int year, month, day;

    if (date.length() != 10) {
        return false;
    }
    if (date[4] != '-' || date[7] != '-') {
        return false;
    }
    char dash1, dash2;
    ss >> year >> dash1 >> month >> dash2 >> day;
    if ((year < 2009 || year > 2023) || (month < 1  || month > 12) || (day < 1 || day > 31)){
        return false;
    }
    if ((month == 2 || month == 4 || month == 6 || month == 9 || month == 11) && day == 31) {
        return false;
    }
    if (month == 2 && (day == 30 || day == 29)) {
        return false;
    }
    return true;
}

int     BitcoinExchange::checkValue(std::string& value) {
    std::istringstream  ss(value);
    int                 n;
    
    ss >> n;
    if (n < 0) {
        return -1;
    } else if (n > 1000) {
        return 1001;
    }
    return 0;
}

std::string BitcoinExchange::getPreviousDate(std::string& current) {
    int year, month, day;
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    year = std::stoi(current.substr(0, 4));
    month = std::stoi(current.substr(5, 2));
    day = std::stoi(current.substr(8, 2));

    day--;
    if (day == 0) {
        month--;
        if (month == 0) {
            month = 12;
            year--;
        }
        day = daysInMonth[month];
    }

    std::string prev_year, prev_month, prev_day;
    
    prev_year = std::to_string(year);
    if (month < 10) {
        prev_month = "0" + std::to_string(month);
    } else {
        prev_month = std::to_string(month);
    }
    if (day < 10) {
        prev_day = "0" + std::to_string(day);
    } else {
        prev_day = std::to_string(day);    
    }
    
    return (prev_year + "-" + prev_month + "-" + prev_day);
}
