/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:53:14 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/17 15:24:21 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <fstream>
# include <sstream>

class   BitcoinExchange {
    private:
        std::ifstream                   txtFile;
        std::ifstream                   dbFile;
        std::map<std::string, double>   dataMap;

        bool                isValidValue(const std::string& value);
        
    public:
        BitcoinExchange();
        BitcoinExchange(const char* txt, const char* db);
        BitcoinExchange(const BitcoinExchange& other);
        ~BitcoinExchange();

        BitcoinExchange&    operator=(const BitcoinExchange& other);
        
        bool                processFile();
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : txtFile(new std::ifstream(*(other.txtFile))), dbFile(new std::ifstream(*(other.dbFile))), dataMap(other.dataMap) {}

#endif