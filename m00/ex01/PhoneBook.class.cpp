/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:34:28 by viferrei          #+#    #+#             */
/*   Updated: 2023/04/11 22:53:43 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <typeinfo>	// typeid

void	PhoneBook::add_contact() {
	static int	index = 0;
	int			phone_number;

	if (index == 8)
		index = 0;
	std::cout << "First name:" << std::endl;
	std::cin >> contacts[index].firstname;
	std::cout << "Last name:" << std::endl;
	std::cin >> contacts[index].lastname;
	std::cout << "Nickname:" << std::endl;
	std::cin >> contacts[index].nickname;
	std::cout << "Phone number:" << std::endl;
	std::cin >> phone_number;
	if (std::cin.fail() || phone_number < 0) {
		std::cout << "Invalid phone number" << std::endl;
		exit(1);
	}
	contacts[index].phone_number = phone_number;
	std::cout << "Darkest secret:" << std::endl;
	std::cin >> contacts[index].darkest_secret;
	index++;
}

void	PhoneBook::search_contact() {

}

void	PhoneBook::delete_and_exit() {

}
