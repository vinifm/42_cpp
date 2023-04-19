/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:34:28 by viferrei          #+#    #+#             */
/*   Updated: 2023/04/19 18:47:53 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

void	PhoneBook::add_contact() {
	std::string	name;
	static int	index = 0;

	if (index == 8)
		index = 0;
	this->contacts[index].firstname = validate_name("First name:");
	this->contacts[index].lastname = validate_name("Last name:");
	this->contacts[index].nickname = validate_name("Nickname:");
	this->contacts[index].phone_number = validate_phone();
	std::cout << "Darkest secret:" << std::endl;
	std::cin >> this->contacts[index].darkest_secret;
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	std::cout << "CONTACT ADDED SUCCESSFULLY" << std::endl;
}

void	PhoneBook::search_contact() {

}

/* Check if all input characters are alphabetical */
std::string	PhoneBook::validate_name(std::string info) {
	bool		not_valid;
	std::string	str;

	do {
		not_valid = false;
		std::cout << info << std::endl;
		std::cin >> str;
		for (std::string::iterator it = str.begin();
				it != str.end(); it++) {
			if(!isalpha(*it))
				not_valid = true;
		}
		if (not_valid)
			std::cout << "ERROR: Name must have only alphabetical characters" \
				<< std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	} while (not_valid);
	return (str);
}

/* Check if phone is numeric */
std::string	PhoneBook::validate_phone() {
	bool			not_valid;
	std::string		phone_number;

	do {
		not_valid = false;
		std::cout << "Phone number:" << std::endl;
		std::cin >> phone_number;

		for (std::string::iterator it = phone_number.begin();
				it != phone_number.end(); it++) {
			if(!isdigit(*it))
				not_valid = true;
		}
		if (not_valid)
			std::cout << "ERROR:  Invalid phone number" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	} while (not_valid);
	return phone_number;
}

