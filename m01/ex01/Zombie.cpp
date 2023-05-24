/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:10:52 by viferrei          #+#    #+#             */
/*   Updated: 2023/05/24 17:27:05 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* Constructors and destructor */
Zombie::Zombie(std::string name) : name(name) {}
Zombie::Zombie(const Zombie& copy) : name(copy.name) {}

Zombie& Zombie::operator=(const Zombie& assign) {
	if (this != &assign)
		name = assign.name;
	return *this;
}

Zombie::~Zombie() {
	std::cout << name << " has died (again)" << std::endl;
}

/* Setter */
void	Zombie::setName(std::string name) {
	this->name = name;
}

/* Member function */
void	Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

