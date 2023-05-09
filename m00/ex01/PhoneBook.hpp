/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:19:16 by viferrei          #+#    #+#             */
/*   Updated: 2023/05/09 19:30:01 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <ctype.h>	// isalpha, isdigit
#include <cstdlib>	// exit
#include <string>	// atoi
#include <iomanip>

class	Contact {
public:
	Contact() : added(false) {}

	bool			added;
	std::string		firstname;
	std::string		lastname;
	std::string		nickname;
	std::string		phone_number;
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
	int				validate_index();
	std::string		validate_phone(std::string input_msg);
	void			display_all_contacts();
	std::string		truncate_str(std::string str);
};

#endif