/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:09:10 by dcologgi          #+#    #+#             */
/*   Updated: 2023/11/08 12:23:41 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <string>
# include <vector>
# include <iostream>
# include <iomanip>

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string secret;

	public:
		Contact(const std::string& _firstName,
			const std::string& _lastName,
			const std::string& _nickname,
			const std::string& _phoneNumber,
			const std::string& _secret);

		std::string getFirstName() const { return firstName; }
		std::string getLastName() const { return lastName; }
		std::string getNickname() const { return nickname; }
		std::string getPhoneNumber() const { return phoneNumber; }
		std::string getSecret() const { return secret; }
};

class PhoneBook {
	private:
		std::vector<Contact> contacts;
	
	public:
		PhoneBook();
		
		void addContact();
		void searchContact();
};

#endif