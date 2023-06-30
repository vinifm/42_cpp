/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:50:54 by viferrei          #+#    #+#             */
/*   Updated: 2023/06/29 22:07:36 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*--- CONSTRUCTORS AND DESTRUCTOR --------------------------------------------*/

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_name			= name;
	_hitPoints		= 100;
	_energyPoints	= 50;
	_attackDamage	= 20;
	_className		= "\033[1;36mScavTrap \033[0m";
	std::cout << "A wild " << display_name() << "has appeared!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy) {
	*this = copy;
	std::cout << display_name() << "Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {
	if (this != &rhs) {
		_name			= rhs.getName();
		_hitPoints		= rhs.getHitPoints();
		_energyPoints	= rhs.getEnergyPoints();
		_attackDamage	= rhs.getAttackDamage();
		_className		= rhs.getClassName();
	}
	std::cout << display_name()
		<< "Copy assignment operator called" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << display_name() << "has come to passed..." << std::endl;
}

/*--- MEMBER FUNCTIONS -------------------------------------------------------*/

void	ScavTrap::attack(const std::string& target) {
	if (is_dead() || is_tired())
		return ;
	_energyPoints--;
	std::cout << display_name()
		<< "attacks "
		<< target
		<< " causing "
		<< _attackDamage
		<< " points of damage. Wow, that's actual damage!";
	display_status();
}
