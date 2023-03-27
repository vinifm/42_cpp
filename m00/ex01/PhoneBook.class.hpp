/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:19:16 by viferrei          #+#    #+#             */
/*   Updated: 2023/03/27 19:44:50 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include <string>

class	PhoneBook {

public:
	PhoneBook(void);
	~PhoneBook(void);


};

class	Contact {

public:
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;
	size_t		phone_number;
	std::string	darkest_secret;
};

#endif
