/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:03:28 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/08 14:18:54 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"

// Build delle classi
Contact::Contact(const std::string& _firstName, const std::string& _lastName,
	const std::string& _nickname, const std::string& _phoneNumber,
	const std::string& _secret)
	: firstName(_firstName), lastName(_lastName), nickname(_nickname),
	phoneNumber(_phoneNumber), secret(_secret) {        
}

PhoneBook::PhoneBook() {
}


// ADD
void PhoneBook::addContact() {

    // Rimuovi il contatto più vecchio se la rubrica é piena
	if (contacts.size() == 8) {
        contacts.erase(contacts.begin());
    }
	
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string secret;
	
	// Creazione contatto
	std::cout << "Enter first name: ";
	std::cin.ignore();
	std::getline(std::cin, firstName);
	
	std::cout << "Enter last name: ";
	std::getline(std::cin, lastName);
	
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
	
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phoneNumber);
	
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, secret);

	// Esito creazione contatto
	if (!firstName.empty() && !lastName.empty() && !nickname.empty()
		&& !phoneNumber.empty() && !secret.empty()) {
			contacts.push_back(Contact(firstName, lastName, nickname, phoneNumber, secret));
			std::cout << "✅ Contact added successfully! ✅" << std::endl;
	} else {
		std::cout << "🙅 Contact not added. All fields must be non-empty 🙅" << std::endl;
	}
}


// SEARCH
void PhoneBook::searchContact() {
	// Rubrica vuota 
	if (contacts.empty()) {
		std::cout << "🤷 Phonebook is empty. Please add contacts first 🤷" << std::endl;
		return;
	}
	
	// Stampa dei titoli delle colonne
	std::cout << std::setw(10) << "Index" << " | " << std::setw(10) << "First Name" << " | " << std::setw(10) << "Last Name" << " | " << std::setw(10) << "Nickname" << std::endl;
	
	// Troncamento info contatto
	for (size_t i = 0; i < contacts.size(); i++) {
		std::string displayFirst = contacts[i].getFirstName();
		std::string displayLast = contacts[i].getLastName();
		std::string displayNick = contacts[i].getNickname();
		if (displayFirst.size() > 10) {
			displayFirst = displayFirst.substr(0, 9) + ".";
		}
		if (displayLast.size() > 10) {
			displayLast = displayLast.substr(0, 9) + ".";
		}
		if (displayFirst.size() > 10) {
			displayNick = displayNick.substr(0, 9) + ".";
		}
		std::cout << std::setw(10) << i << " | " << std::setw(10) << displayFirst << " | " << std::setw(10) << displayLast << " | " << std::setw(10) << displayNick << std::endl;
	}

	std::cout << "Enter the index of the contact you want to display: ";
	int index;
	std::cin >> index;

	// Mostra info contatto
	if (index >= 0 && static_cast<size_t>(index) < contacts.size()) {
		std::cout << "Contact Information:" << std::endl;
		std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
		std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
		std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
		std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << contacts[index].getSecret() << std::endl;
	} else {
		std::cout << "❌ Invalid index. Contact not found ❌" << std::endl;
	}
}