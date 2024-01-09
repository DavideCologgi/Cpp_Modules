/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:36:58 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/09 15:22:21 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
# include <cstdint>

class Serializer : public Data {
    public:
        Serializer();
        Serializer(const Serializer& other);
        ~Serializer();

        Serializer& operator=(const Serializer& other);
        
        uintptr_t   serialize(Data* ptr);
        Data*       deserialize(uintptr_t raw);
};

#endif