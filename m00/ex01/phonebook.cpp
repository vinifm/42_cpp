/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:02:04 by viferrei          #+#    #+#             */
/*   Updated: 2023/04/19 18:40:22 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
//	A simple phonebook program.
//	Prompt the user to enter one of the following commands: ADD, SEARCH, EXIT.
//		- ADD: prompt the user to enter contact info one field at a time and add
//	it to phonebook. Empty fields are not accepted.
//		- SEARCH: display all saved contacts then prompt the index of the entry
//	to display.
//		- EXIT: delete contacts and quit.
*/

#include "PhoneBook.class.hpp"
#include "PhoneBook.class.cpp"

/* Check for invalid input */
void	invalid_cmd(std::string cmd) {
	try {
		if (cmd.compare("ADD") != 0
			&& cmd.compare("SEARCH") != 0
			&& cmd.compare("EXIT") != 0)
			throw "ERROR: Invalid input";
	}
	catch (const char *error) {
		std::cout << error << std::endl;
	}
}

int	main(void) {
	std::string	cmd;
	PhoneBook	phonebook;

	while (1) {
		std::cout << "enter either ADD, SEARCH, or EXIT:" << std::endl;
		std::cin >> cmd;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		invalid_cmd(cmd);
		if (cmd.compare("ADD") == 0)
			phonebook.add_contact();
		else if (cmd.compare("SEARCH") == 0)
			phonebook.search_contact();
		else if (cmd.compare("EXIT") == 0)
			exit(0);
			// phonebook.delete_and_exit();
	}
}

void	clear_cin_buffer() {
		std::cin.clear();
		std::cin.ignore(1000, '\n');
}
