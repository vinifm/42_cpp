/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:48:14 by viferrei          #+#    #+#             */
/*   Updated: 2023/06/28 17:37:35y viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*--- CONSTRUCTORS AND DESTRUCTOR --------------------------------------------*/

ClapTrap::ClapTrap(std::string name)
	: _name(name),
		_hitPoints(10),
		_energyPoints(10),
		_attackDamage(0),
		_className("\033[1;33mClapTrap \033[0m") {
	std::cout << display_name() << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy) {
	*this = copy;
	std::cout << display_name() << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
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

ClapTrap::~ClapTrap() {
	std::cout << display_name() << "Destructor called" << std::endl;
}

/*--- MEMBER FUNCTIONS -------------------------------------------------------*/

void	ClapTrap::attack(const std::string& target) {
	if (is_dead() || is_tired())
		return ;
	_energyPoints--;
	std::cout << display_name()
		<< "attacks "
		<< target
		<< " causing "
		<< _attackDamage
		<< " points of damage. Unimpressive..." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (amount > _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints = _hitPoints - amount;
	std::cout << display_name()
		<< "takes "
		<< amount
		<< " points of damage! Ouch!"
		<< std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (is_dead() || is_tired())
		return ;
	_hitPoints = _hitPoints + amount;
	_energyPoints--;
	std::cout << display_name() << "repairs itself." << std::endl;
}

/* Return true if there is no more HP */
bool	ClapTrap::is_dead() {
	if (_hitPoints > 0)
		return false;
	std::cout << display_name()
		<< "has no more hit points. RIP :("
		<< std::endl;
	return true;
}

/* Return true if there is no more energy points */
bool	ClapTrap::is_tired() {
	if (_energyPoints > 0)
		return false;
	std::cout << display_name() << "is out of energy points!" << std::endl;
	return true;
}

std::string	ClapTrap::display_name() {
	return (_className + _name + " ");
}

/* Display HP and energy points */
void	ClapTrap::display_status() {
	std::cout << display_name()
		<< " has "
		<< _hitPoints
		<< " HP and "
		<< _energyPoints
		<< " Energy points "
		<< std::endl;
}

/*--- GETTERS ----------------------------------------------------------------*/

std::string		ClapTrap::getName() const { return _name; }
unsigned int	ClapTrap::getHitPoints() const { return _hitPoints; }
unsigned int	ClapTrap::getEnergyPoints() const { return _energyPoints; }
unsigned int	ClapTrap::getAttackDamage() const { return _attackDamage; }
std::string		ClapTrap::getClassName() const { return _className; }
