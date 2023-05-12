/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_getset.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:27:20 by viferrei          #+#    #+#             */
/*   Updated: 2023/05/12 16:50:28 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/* Accessors */
bool	Contact::getAdded() const {
	return (this->added);
}

std::string	Contact::getFirstname() const {
	return (this->firstname);
}

std::string	Contact::getLastname() const {
	return (this->lastname);
}

std::string	Contact::getNickname() const {
	return (this->nickname);
}

std::string	Contact::getPhone_number() const {
	return (this->phone_number);
}

std::string	Contact::getDarkest_secret() const {
	return (this->darkest_secret);
}

/* Mutators */
void	Contact::setAdded(bool added) {
	this->added = added;
}
void	Contact::setFirstname(std::string firstname) {
	this->firstname = firstname;
}
void	Contact::setLastname(std::string lastname) {
	this->lastname = lastname;
}
void	Contact::setNickname(std::string nickname) {
	this->nickname = nickname;
}
void	Contact::setPhone_number(std::string phone_number) {
	this->phone_number = phone_number;
}
void	Contact::setDarkest_secret(std::string darkest_secret) {
	this->darkest_secret = darkest_secret;
}
