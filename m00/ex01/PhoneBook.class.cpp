/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:34:28 by viferrei          #+#    #+#             */
/*   Updated: 2023/04/29 18:28:39 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

void	PhoneBook::add_contact() {
	std::string	name;
	static int	index = 0;

	if (index == 8)
		index = 0;
	this->contacts[index].added = true;
	this->contacts[index].firstname = validate_name("First name:");
	this->contacts[index].lastname = validate_name("Last name:");
	this->contacts[index].nickname = validate_name("Nickname:");
	this->contacts[index].phone_number = validate_number("Phone number:");
	std::cout << "Darkest secret:" << std::endl;
	std::cin >> this->contacts[index].darkest_secret;
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	std::cout << "CONTACT ADDED SUCCESSFULLY" << std::endl;
}

void	PhoneBook::search_contact() {
	unsigned int	index;

	std::cout << std::setiosflags(std::ios::right);
	std::cout << std::setw(10) << "index";
	std::cout << "|";
	std::cout << std::setw(10) << "first name";
	std::cout << "|";
	std::cout << std::setw(10) << "last name";
	std::cout << "|";
	std::cout << std::setw(10) << "nickname" << std::endl;
	for (int i = 0; this->contacts[i].added == true; i++) {
		std::cout << std::setw(10) << i;
		std::cout << "|";
		std::cout << std::setw(10) << truncate_str(this->contacts[i].firstname);
		std::cout << "|";
		std::cout << std::setw(10) << truncate_str(this->contacts[i].lastname);
		std::cout << "|";
		std::cout << std::setw(10) << truncate_str(this->contacts[i].nickname)\
			 << std::endl;
	}
	index = validate_number("Enter an index:");
	if (this->contacts[index].added == true) {

	}
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

/* Check if input is numeric */
unsigned int PhoneBook::validate_number(std::string input_msg) {
	bool			not_valid;
	std::string		phone_number;

	do {
		not_valid = false;
		std::cout << input_msg << std::endl;
		std::cin >> phone_number;

		for (std::string::iterator it = phone_number.begin();
				it != phone_number.end(); it++) {
			if(!isdigit(*it))
				not_valid = true;
		}
		if (not_valid)
			std::cout << "ERROR: Invalid number" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	} while (not_valid);
	return (std::stoi(phone_number));
}

/*
//	If str is longer than 11 characters, truncate str and replace the 10th
//	character with a dot
*/
std::string	PhoneBook::truncate_str(std::string str) {
	if (str.size() > 10)
		return (str.substr(0, 9) + ".");
	return (str.substr(0, 10));
}
