/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:14:23 by viferrei          #+#    #+#             */
/*   Updated: 2023/06/05 18:45:16 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {}
HumanB::HumanB(const HumanB& copy) : _name(copy._name), _weapon(copy._weapon) {}
HumanB& HumanB::operator=(const HumanB& assign) {
	if (this != &assign) {
		_name = assign._name;
		_weapon = assign._weapon;
	}
	return *this;
}
HumanB::~HumanB() {
	std::cout << "HumanB " << _name << " was destroyed" << std::endl;
}

void HumanB::setWeapon(Weapon* weapon) {
	_weapon = weapon;
}

void HumanB::attack() {
	std::cout << _name << " attacks with " << _weapon->getType() << std::endl;
}
