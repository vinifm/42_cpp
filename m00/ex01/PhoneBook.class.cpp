/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:34:28 by viferrei          #+#    #+#             */
/*   Updated: 2023/04/17 20:32:04 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

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
	} while (not_valid);
	return (str);
}

/* Check if phone is numeric */
int	PhoneBook::validate_phone() {
	bool		not_valid;
	int		phone_number;

	do {
		not_valid = false;
		std::cout << "Phone number:" << std::endl;
		std::cin >> phone_number;
		if (std::cin.fail() || phone_number < 0) {
			std::cout << "ERROR: Invalid phone number" << std::endl;
			not_valid = true;
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
	} while (not_valid);
	return phone_number;
}

/* Check if all input info is valid */
void	PhoneBook::get_contact_info(Contact *new_contact) {
	std::string	firstname, lastname, nickname, darkest_secret;

	new_contact->firstname = validate_name("First name:");
	new_contact->lastname = validate_name("Last name:");
	new_contact->nickname = validate_name("Nickname:");
	new_contact->phone_number = validate_phone();
	std::cout << "Darkest secret:" << std::endl;
	std::cin >> new_contact->darkest_secret;
	std::cout << "CONTACT ADDED SUCCESSFULLY\n" << std::endl;
}

void	PhoneBook::add_contact() {
	static int	index = 0;

	if (index == 8)
		index = 0;
	get_contact_info(this->contacts);
}

void	PhoneBook::search_contact() {

}

void	PhoneBook::delete_and_exit() {

}
