/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:34:28 by viferrei          #+#    #+#             */
/*   Updated: 2023/04/11 22:27:46 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <typeinfo>	// typeid

/* Check if all input info is valid */
void	PhoneBook::validate_contact_info(Contact *new_contact) {
	std::string	firstname, lastname, nickname, darkest_secret;
	size_t		phone_number;
	bool		not_valid;

	do {
		not_valid = false;
		std::cout << "First name: " << std::endl;
		std::cin >> firstname;
		for (std::string::iterator it = firstname.begin();
				it != firstname.end(); it++) {
			if(!isalpha(*it))
				not_valid = true;
		}
		if (not_valid)
			std::cout << "Name must have only alphabetical characters" << std::endl;
	} while (not_valid);

	std::cout << "Last name: " << std::endl;
	std::cin >> lastname;
	std::cout << "Nickname: " << std::endl;
	std::cin >> nickname;
	std::cout << "Phone number: " << std::endl;
	std::cin >> phone_number;
	std::cout << "Darkest secret: " << std::endl;
	std::cin >> darkest_secret;

	new_contact->firstname = firstname;
}

void	PhoneBook::add_contact() {
	static int	index;
	Contact		new_contact;

	index = 0;
	validate_contact_info(&new_contact);

}

void	PhoneBook::search_contact() {

}

void	PhoneBook::delete_and_exit() {

}
