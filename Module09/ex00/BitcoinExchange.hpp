/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:53:14 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/18 14:02:14 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <cstdlib>

class   BitcoinExchange {
    private:
        std::map<std::string, std::string>   dataMap;

        std::string getPreviousDate(std::string& current);
        bool        checkDate(std::string& date);
        int         checkValue(std::string& value);

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        ~BitcoinExchange();

        BitcoinExchange&    operator=(const BitcoinExchange& other);
        
        void                processFile(const std::string& file);
};

#endif