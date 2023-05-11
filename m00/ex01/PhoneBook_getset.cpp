/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_getset.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:27:20 by viferrei          #+#    #+#             */
/*   Updated: 2023/05/11 18:48:45 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/* Accessors */
bool	Contact::getAdded() const {
	return (this->added);
}

std::string	getFirstname() const {
	return (this->firstname);
}

std::string	getLastname const {
	return (this->lastname);
}

std::string	getNickname() const {
	return (this->nickname);
}

std::string	getPhone_number const {
	return (this->phone_number);
}

std::string	getDarkest_secret() const {
	return (this->darkest_secret);
}

/* Mutators */
void			setAdded(bool added) {
	this->added = added;
}
void			setFirstname(std::string firstname) {
	this->firstname = firstname;
}
void			setLastname(std::string lastname) {
	this->lastname = lastname;
}
void			setNickname(std::string nickname) {
	this->nickname = nickname;
}
void			setPhone_number(std::string phone_number) {
	this->phone_number = phone_number;
}
void			setDarkest_secret(std::string darkest_secret) {
	this->darkest_secret = darkest_secret;
}
