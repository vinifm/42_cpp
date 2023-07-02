/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 19:07:30 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/02 20:15:42 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*--- CONSTRUCTORS AND DESTRUCTOR --------------------------------------------*/

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	setName(name);
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	setClassName("\033[1;92mFragTrap \033[0m");
	std::cout << "A lovely " << display_name() << "showed up! Nice little fella."
		<< std::endl;
}
FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy) {
	*this = copy;
	std::cout << B_GREEN << "FragTrap " << RESET << getName()
		<< " Copy constructor called" << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap& rhs) {
	if (this != &rhs) {
		setName(rhs.getName());
		setHitPoints(rhs.getHitPoints());
		setEnergyPoints(rhs.getEnergyPoints());
		setAttackDamage(rhs.getAttackDamage());
		setClassName("\033[1;92mFragTrap \033[0m");
	}
	std::cout << B_GREEN << "FragTrap " << RESET << getName()
		<< " Copy assignment called" << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << display_name() << "is gone. You'll probably never see it again."
		<< std::endl;
}

/*--- MEMBER FUNCTIONS -------------------------------------------------------*/

void	FragTrap::highFiveGuys() {
	if (is_dead() || is_tired())
		return ;
	std::cout << display_name() << "is asking for a high five! Come here!"
		<< std::endl;
}
