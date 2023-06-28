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
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		_name = rhs.getName();
		_hitPoints = rhs.getHitPoints();
		_energyPoints = rhs.getEnergyPoints();
		_attackDamage = rhs.getAttackDamage();
	}
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

/*--- MEMBER FUNCTIONS -------------------------------------------------------*/

void	ClapTrap::attack(const std::string& target) {
	if (is_dead() || is_tired())
		return ;
	_energyPoints--;
	std::cout << "ClapTrap "
		<< _name
		<< "attacks "
		<< target
		<< "causing "
		<< _attackDamage
		<< "points of damage";
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap "
		<< _name
		<< "takes "
		<< amount
		<< "points of damage! Ouch!";
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (is_dead() || is_tired())
		return ;
	_hitPoints = _hitPoints + amount;
	_energyPoints--;
	std::cout << "ClapTrap"
		<< _name
		<< "repairs itself and now has "
		<< _hitPoints
		<< "HP"
		<< std::endl;
}

/* Return true if there is no more HP */
bool	ClapTrap::is_dead(void) {
	if (_hitPoints > 0)
		return false;
	std::cout << "ClapTrap "
		<< _name
		<< "has no more hit points. RIP :("
		<< std::endl;
	return true;
}

/* Return true if there is no more energy points */
bool	ClapTrap::is_tired(void) {
	if (_energyPoints > 0)
		return false;
	std::cout << "ClapTrap "
		<< _name
		<< "is out of energy points!"
		<< std::endl;
	return true;
}

/*--- GETTERS ----------------------------------------------------------------*/

std::string		ClapTrap::getName() const { return _name; }
unsigned int	ClapTrap::getHitPoints() const { return _hitPoints; }
unsigned int	ClapTrap::getEnergyPoints() const { return _energyPoints; }
unsigned int	ClapTrap::getAttackDamage() const { return _attackDamage; }
