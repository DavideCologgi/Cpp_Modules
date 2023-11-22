/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:22:15 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/22 14:47:27 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void) {
	Point	a;
	Point	b(3, 4);
	Point	c(5.05f, 0.0f);
	
	Point	insidePoint(2.0f, 1.5f);
	Point	onVertexPoint(3, 4);
	Point	onEdgePoint(3.5f, 0.0f);
	Point	outsidePoint(6, 7.1f);

	bool insideResult = bsp(a, b, c, insidePoint);
	bool onVertexResult = bsp(a, b, c, onVertexPoint);
	bool onEdgeResult = bsp(a, b, c, onEdgePoint);
	bool outsideResult = bsp(a, b, c, outsidePoint);
	
	std::cout << "Inside point result: " << (insideResult ? "Inside" : "Outside")
		<< std::endl;
	std::cout << "On vertex point result: " << (onVertexResult ? "Inside" : "Outside")
		<< std::endl;
	std::cout << "On edge point result: " << (onEdgeResult ? "Inside" : "Outside")
		<< std::endl;
	std::cout << "Outside point result: " << (outsideResult ? "Inside" : "Outside")
		<< std::endl;
	return (0);
}