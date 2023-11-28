/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:23:52 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/28 16:38:23 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class   MateriaSource : public IMateriaSource {
    private:
        AMateria* learnedMat[4];

    public:
        MateriaSource();
        ~MateriaSource();

        void        learnMateria(AMateria* materia);
        AMateria*   createMateria(std::string const &type);
};

#endif