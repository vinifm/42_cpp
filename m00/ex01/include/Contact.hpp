/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:23:22 by viferrei          #+#    #+#             */
/*   Updated: 2023/05/17 17:16:41 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CONTACT_HPP
# define CONTACT_HPP

#include <string>

class	Contact {
public:
	Contact() : added(false) {}

	bool			getAdded() const;
	std::string		getFirstname() const;
	std::string		getLastname() const;
	std::string		getNickname() const;
	std::string		getPhone_number() const;
	std::string		getDarkest_secret() const;

	void			setAdded(bool added);
	void			setFirstname(std::string firstname);
	void			setLastname(std::string lastname);
	void			setNickname(std::string nickname);
	void			setPhone_number(std::string phone_number);
	void			setDarkest_secret(std::string darkest_secret);

private:
	bool			added;
	std::string		firstname;
	std::string		lastname;
	std::string		nickname;
	std::string		phone_number;
	std::string		darkest_secret;
};

#endif
