/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:10:52 by viferrei          #+#    #+#             */
/*   Updated: 2023/05/19 17:59:13 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/*	Create a zombie, name it, and return it so you can use it outside of the
	function scope */
Zombie*	newZombie(std::string name) {

}

/* Constructors and destructor */
Zombie::Zombie() : name("Unknown") {}

Zombie::Zombie(const Zombie& copy) {
	name = copy.name;
}

Zombie& Zombie::operator=(const Zombie& assign) {
	if (this != &assign)
		name = assign.name;
	return *this;
}

Zombie::~Zombie() {}
