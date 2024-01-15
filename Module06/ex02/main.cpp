/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:21:07 by dcologgi          #+#    #+#             */
/*   Updated: 2024/01/15 14:36:01 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base*   generate() {
    int x;
    std::srand(std::time(0));

    x = std::rand() % 3;
    switch (x) {
        case 0:
            return (new A);
        
        case 1:
            return (new B);

        case 2:
            return (new C);
        
        default:
            break;
    }
    return NULL;
}

void    identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A*" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B*" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C*" << std::endl;
    else
        std::cout << "unknown type" << std::endl;
}

void    identify(Base& p) {
    Base	a;

	try {
        a = dynamic_cast<A&>(p);
        std::cout << "A&" << std::endl;
        return ;
    } catch (std::exception &e) {}
	try {
        a = dynamic_cast<B&>(p);
        std::cout << "B&" << std::endl;
        return ;
    } catch (std::exception &e) {}
	try {
        a = dynamic_cast<C&>(p);
        std::cout << "C&" << std::endl;
        return ;
    } catch (std::exception &e) {}
}

int main() {
    Base    *x;
    
    x = generate();

    Base    &y = *x;

    identify(x);
    identify(y);

    delete x;

    return 0;
}