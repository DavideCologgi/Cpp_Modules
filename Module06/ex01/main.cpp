/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:08:46 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/09 15:16:12 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main () {
    Serializer  serial;

    Data*       originData;
    Data*       returnData;
    uintptr_t   raw;
    
    originData = new Data;
    
    raw = serial.serialize(originData);
    returnData = serial.deserialize(raw);

    std::cout << "Origin data: " << originData << std::endl;
    std::cout << "Serialized data: " << raw << std::endl;
    std::cout << "Deserialized data: " << returnData << std::endl;
    
    delete originData;
    
    return 0;
}