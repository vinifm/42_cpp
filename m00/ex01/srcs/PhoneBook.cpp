/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:34:28 by viferrei          #+#    #+#             */
/*   Updated: 2023/05/17 17:19:32 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

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
	contact->setPhone_number(validate_phone("Phone number:"));
	std::cout << "Darkest secret:" << std::endl;
	while (true) {
		if (std::cin.eof())
			return;
		std::getline(std::cin, secret);
		if (secret == "")
			continue;
		contact->setDarkest_secret(secret);
		break;
	}
	contact->setAdded(true);
	std::cout << "CONTACT ADDED SUCCESSFULLY" << std::endl;
	index++;
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
	else if (index == -2)
		return ;
	contact = &this->contacts[index];
	if (contact->getAdded() == true) {
		std::cout << "First name: " << contact->getFirstname() << std::endl;
		std::cout << "Last name: " << contact->getLastname() << std::endl;
		std::cout << "Nickname: " << contact->getNickname() << std::endl;
		std::cout << "Phone number: " << contact->getPhone_number() << std::endl;
		std::cout << "Darkest secret: " << contact->getDarkest_secret() \
			<< std::endl;
	}
	else
		std::cout << "ERROR: index out of reach" << std::endl;
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
	for (int i = 0; this->contacts[i].getAdded() == true; i++) {
		std::cout << std::setw(10) << i;
		std::cout << "|";
		std::cout << std::setw(10) << truncate_str(this->contacts[i].getFirstname());
		std::cout << "|";
		std::cout << std::setw(10) << truncate_str(this->contacts[i].getLastname());
		std::cout << "|";
		std::cout << std::setw(10) << truncate_str(this->contacts[i].getNickname())\
			 << std::endl;
	}
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
