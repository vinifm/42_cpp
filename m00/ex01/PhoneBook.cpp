/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:34:28 by viferrei          #+#    #+#             */
/*   Updated: 2023/05/11 19:09:58 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::add_contact() {
	static int	index = 0;
	Contact		*contact;
	std::string	secret;

	if (index == 8)
		index = 0;
	contact = &this->contacts[index];
	contact->setFirstname(validate_name("First name:"));
	contact->setLastname(validate_name("Last name:"));
	contact->setNickname(validate_name("Nickname:"));
	contact->setPhone_number(validate_name("Phone number:"));
	while(std::getline(std::cin, secret) && !secret.empty()) {
		std::cout << "Darkest secret:" << std::endl;
		contact->setDarkest_secret(secret);
		if (std::cin.eof())
			return;
	}
	contact->setAdded(true);
	std::cout << "CONTACT ADDED SUCCESSFULLY" << std::endl;
	index++;
}

void	PhoneBook::display_all_contacts() {
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
}

void	PhoneBook::search_contact() {
	int				index;
	Contact			*contact;

	display_all_contacts();
	index = validate_index();
	if (std::cin.eof())
		return;
	if (index == -1) {
		std::cout << "ERROR: index out of reach" << std::endl;
		return ;
	}
	contact = &this->contacts[index];
	if (contact->added == true) {
		std::cout << "First name: " << contact->firstname << std::endl;
		std::cout << "Last name: " << contact->lastname << std::endl;
		std::cout << "Nickname: " << contact->nickname << std::endl;
		std::cout << "Phone number: " << contact->phone_number << std::endl;
		std::cout << "Darkest secret: " << contact->darkest_secret << std::endl;
	}
	else
		std::cout << "ERROR: index out of reach" << std::endl;
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

/* Check if input string is numeric */
std::string PhoneBook::validate_phone(std::string input_msg) {
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
	return (phone_number);
}

/* Check if input is numeric and returns an integer*/
int PhoneBook::validate_index() {
	bool			not_valid;
	std::string		number;
	int				number_int;

	do {
		not_valid = false;
		std::cout << "Enter an index:" << std::endl;
		std::cin >> number;
		for (std::string::iterator it = number.begin();
				it != number.end(); it++) {
			if(!isdigit(*it))
				not_valid = true;
		}
		if (not_valid)
			std::cout << "ERROR: Invalid number" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	} while (not_valid);
	number_int = std::atoi(number.c_str());
	if (number_int >= 0 && number_int < 8)
		return (number_int);
	return (-1);
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
