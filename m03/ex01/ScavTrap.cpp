/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:50:54 by viferrei          #+#    #+#             */
/*   Updated: 2023/06/30 18:18:30 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*--- CONSTRUCTORS AND DESTRUCTOR --------------------------------------------*/

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	setName(name);
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "A wild " << display_name() << "has appeared!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy) {
	*this = copy;
	std::cout << display_name() << "Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {
	std::cout << display_name()
		<< "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		setName(rhs.getName());
		setHitPoints(rhs.getHitPoints());
		setEnergyPoints(rhs.getEnergyPoints());
		setAttackDamage(rhs.getAttackDamage());
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << display_name() << "has come to passed..." << std::endl;
}

/*--- MEMBER FUNCTIONS -------------------------------------------------------*/

void	ScavTrap::attack(const std::string& target) {
	if (is_dead() || is_tired())
		return ;
	setEnergyPoints(getEnergyPoints() - 1);
	std::cout << display_name()
		<< "attacks "
		<< target
		<< " causing "
		<< getAttackDamage()
		<< " points of damage. Wow, that's actual damage! It now has "
		<< getEnergyPoints()
		<< " energy points"
		<< std::endl;
}

void	ScavTrap::guardGate() {
	std::cout << display_name() << "starts to listen to 'Gatekeeper' by "
		"Canadian indie pop singer-songwriter and guitarist Feist. Gate kept!"
		<< std::endl;
}

std::string	ScavTrap::display_name() {
	return ("\033[1;36mScavTrap \033[0m" + getName() + " ");
}
