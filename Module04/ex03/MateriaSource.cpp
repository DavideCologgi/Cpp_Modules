/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:27:45 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/28 16:38:17 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        learnedMat[i] = NULL;
    }
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        delete learnedMat[i];
    }
}

void MateriaSource::learnMateria(AMateria* materia) {
    for (int i = 0; i < 4; ++i) {
        if (!learnedMat[i]) {
            learnedMat[i] = materia->clone();
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; ++i) {
        if (learnedMat[i] && learnedMat[i]->getType() == type) {
            return learnedMat[i]->clone();
        }
    }
    return (NULL);
}