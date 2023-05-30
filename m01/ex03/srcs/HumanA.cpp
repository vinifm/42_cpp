/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:00:03 by viferrei          #+#    #+#             */
/*   Updated: 2023/05/30 18:19:38 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon) : _name(name), _weapon(weapon) {}
HumanA::HumanA(const HumanA& copy) : _name(copy._name), _weapon(copy._weapon) {}
HumanA& HumanA::operator=(const HumanA& assign) {
	if (this != &assign) {
		_name = assign._name;
		_weapon = assign._weapon;
	}
	return *this;
}
HumanA::~HumanA() {
	std::cout << "HumanA " << _name << " was destroyed" << std::endl;
}
