/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:16:02 by viferrei          #+#    #+#             */
/*   Updated: 2023/05/30 18:19:36 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {}
Weapon::Weapon(const Weapon& copy) : _type(copy._type) {}
Weapon& Weapon::operator=(const Weapon& assign) {
	if (this != &assign)
		_type = assign._type;
	return *this;
}
Weapon::~Weapon() {
	std::cout << "Weapon " << _type << " was destroyed" << std::endl;
}

const std::string& Weapon::getType() const {
	return _type;
}

void Weapon::setType(std::string type) {
	_type = type;
}
