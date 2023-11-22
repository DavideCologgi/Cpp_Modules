/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:35:12 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/22 14:53:16 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Funzione che calcola l'area del triangolo 'abc'
Fixed   area(const Point& a, const Point& b, const Point& c) {
    Fixed   result;
    result = (((b.getX() - a.getX()) * (c.getY() - a.getY())) - ((c.getX() - a.getX()) * (b.getY() - a.getY())));
    return (result);
}

bool    bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed   areaAbc = area(a, b, c);
    
    // Calcolo delle aree dei triangoli formati da due punti noti + il 'point' da controllare
    Fixed   areaPbc = area(point, b, c);
    Fixed   areaApc = area(a, point, c);
    Fixed   areaAbp = area(a, b, point);
    
    // Calcolo dei coefficienti dei baricentri dei tre nuovi triangoli
    Fixed   u = areaPbc / areaAbc;
    Fixed   v = areaApc / areaAbc;
    Fixed   w = areaAbp / areaAbc;

    // Controllo della presenza del 'point' all'interno del triangolo 'abc'
    if (u > 0 && v > 0 && w > 0 && (u + v + w < 1)) {
        return (true);
    } else {
        return (false);
    }
}