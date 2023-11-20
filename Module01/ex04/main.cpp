/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:44:12 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/20 09:56:18 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Wrong parameters: please input a <filename>" <<
            " and a string <s1> to replace with another string <s2>." << std::endl;
        return (1); 
    }

    std::string filename(argv[1]);
    std::string s1(argv[2]);
    std::string s2(argv[3]);

    FileReplace replace(filename, s1, s2);
    replace.replaceAndWriteToFile();
    
    return (0);
}