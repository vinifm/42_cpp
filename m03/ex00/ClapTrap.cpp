/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:48:14 by viferrei          #+#    #+#             */
/*   Updated: 2023/06/27 19:13:52 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy) {
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
}

ClapTrap::~ClapTrap() {
}


void	ClapTrap::attack(const std::string& target) {
}

void	ClapTrap::takeDamage(unsigned int amount) {
}

void	ClapTrap::beRepaired(unsigned int amount) {
}

