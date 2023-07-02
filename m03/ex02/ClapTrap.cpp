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
	std::cout << YELLOW << "ClapTrap " << RESET << getName()
		<< " Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
	if (this != &rhs) {
		_name			= rhs.getName();
		_hitPoints		= rhs.getHitPoints();
		_energyPoints	= rhs.getEnergyPoints();
		_attackDamage	= rhs.getAttackDamage();
		_className		= rhs.getClassName();
	}
	std::cout << YELLOW << "ClapTrap " << RESET << getName()
		<< " Copy assignment operator called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << YELLOW << "ClapTrap " << RESET << getName()
		<< " Destructor called" << std::endl;
}

/*--- MEMBER FUNCTIONS -------------------------------------------------------*/

void	ClapTrap::attack(const std::string& target) {
	if (is_dead() || is_tired())
		return ;
	setEnergyPoints(getEnergyPoints() - 1);
	std::cout << display_name()
		<< "attacks "
		<< target
		<< " causing "
		<< _attackDamage
		<< " points of damage. It now has "
		<< getEnergyPoints()
		<< " energy points."
		<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (amount > getHitPoints())
		setHitPoints(0);
	else
		setHitPoints(getHitPoints() - amount);
	std::cout << display_name()
		<< "takes "
		<< amount
		<< " points of damage! Ouch! It now has "
		<< getHitPoints()
		<< " HP."
		<< std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (is_dead() || is_tired())
		return ;
	setHitPoints(getHitPoints() + amount);
	setEnergyPoints(getEnergyPoints() - 1);
	std::cout << display_name()
		<< "heals "
		<< amount
		<< " HP. It now has "
		<< getHitPoints() << " HP and "
		<< getEnergyPoints() << " energy points."
		<< std::endl;
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
	return (getClassName() + getName() + " ");
}

/*--- GETTERS ----------------------------------------------------------------*/

std::string		ClapTrap::getName() const { return _name; }
unsigned int	ClapTrap::getHitPoints() const { return _hitPoints; }
unsigned int	ClapTrap::getEnergyPoints() const { return _energyPoints; }
unsigned int	ClapTrap::getAttackDamage() const { return _attackDamage; }
std::string		ClapTrap::getClassName() const { return _className; }

/*--- SETTERS ----------------------------------------------------------------*/

void	ClapTrap::setName(std::string str) { _name = str; }
void	ClapTrap::setHitPoints(unsigned int value) { _hitPoints = value; }
void	ClapTrap::setEnergyPoints(unsigned int value) { _energyPoints = value; }
void	ClapTrap::setAttackDamage(unsigned int value) { _attackDamage = value; }
void	ClapTrap::setClassName(std::string str) { _className = str; }
