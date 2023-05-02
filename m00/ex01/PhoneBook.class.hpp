/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:19:16 by viferrei          #+#    #+#             */
/*   Updated: 2023/04/29 18:25:26 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include <string>
#include <iostream>
#include <ctype.h>	// isalpha, isdigit
#include <cstdlib>	// exit
#include <iomanip>

class	Contact {
public:
	Contact() : added(false) {}

	bool		added;
	std::string		firstname;
	std::string		lastname;
	std::string		nickname;
	unsigned int	phone_number;
	std::string		darkest_secret;
};

/*
//	Public:  accessible from inside and outside the class.
//	Private: only accessible from inside the class.
*/
class	PhoneBook {
public:
	void	add_contact();
	void	search_contact();

private:
	Contact		contacts[8];

	std::string		validate_name(std::string);
	unsigned int	validate_number(std::string input_msg);
	std::string		truncate_str(std::string str);
};

#endif
