/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:25:14 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/08 13:58:40 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"

int main() {
	PhoneBook agenda;
	std::string command;

	std::cout << "📞 Welcome to Your Awesome PhoneBook 📖" << std::endl;
	while (true) {
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::cin >> command;

		if (command == "ADD") {
			agenda.addContact();
		}
		else if (command == "SEARCH") {
			agenda.searchContact();
		}
		else if (command == "EXIT") {
			std::cout << "👋 Goodbye! Contacts are lost forever 😢" << std::endl;
			break;
		} else {
			std::cout << "❌ Invalid command. Please enter ADD, SEARCH or EXIT ❌" << std::endl;
		}
	}
	return (0);
}