/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:46:49 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/20 12:22:43 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void    Harl::debug() {
	std::cout << "I love having extra bacon for my "
		<< "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
		<< std::endl;
}

void    Harl::info() {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put"
		<< " enough bacon in my burger! If you did, I wouldn't be asking for more!"
		<< std::endl;
}

void    Harl::warning() {
	std::cout << "I think I deserve to have some extra bacon for free."
		<< " I've been coming for years whereas you started working here since last month."
		<< std::endl;
}

void    Harl::error() {
	std::cout << "This is unacceptable! I want to speak to the manager now."
		<< std::endl;
}

void    Harl::complain(std::string level) {
	void 		(Harl::*ptr_complain[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*ptr_complain[i])();
			break;
		}
	}
}