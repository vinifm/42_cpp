/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_validate.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:28:35 by viferrei          #+#    #+#             */
/*   Updated: 2023/05/12 16:53:54 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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
