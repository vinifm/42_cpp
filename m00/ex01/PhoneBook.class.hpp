/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:19:16 by viferrei          #+#    #+#             */
/*   Updated: 2023/04/17 20:27:18 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include <string>
#include <iostream>
#include <ctype.h>	// isalpha
#include <cstdlib>	// exit
// #include <iomanip>

class	Contact {

public:
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;
	size_t		phone_number;
	std::string	darkest_secret;
};

class	PhoneBook {
// Accessible from inside and outside the class
public:
	// PhoneBook(void);	// constructor
	// ~PhoneBook(void);	// destructor

	void	add_contact();
	void	search_contact();
	void	delete_and_exit();

// Only accessible from inside the class
private:
	Contact		contacts[8];

	std::string	validate_name(std::string);
	int			validate_phone();
	void		get_contact_info(Contact *new_contact);
};

#endif
