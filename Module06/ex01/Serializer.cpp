/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:42:43 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/09 15:17:52 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& other) {
    *this = other;
}

Serializer::~Serializer() {}

Serializer& Serializer::operator=(const Serializer& other) {
    (void) other;
    return *this;
}

uintptr_t   Serializer::serialize(Data* ptr) {
    uintptr_t   ptr_value = reinterpret_cast<uintptr_t>(ptr);

    return ptr_value;
}

Data*       Serializer::deserialize(uintptr_t raw) {
    Data*       data = reinterpret_cast<Data*>(raw);

    return data;
}