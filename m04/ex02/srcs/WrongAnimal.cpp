/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:45:10 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/05 15:24:30 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"

/*--- CONSTRUCTORS AND DESTRUCTOR --------------------------------------------*/

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "A weird" YELLOW " WrongAnimal " RESET
		<< "appears in the horizon."
		<< std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) {
	*this = copy;
	std::cout << YELLOW "WrongAnimal" RESET " Copy constructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& rhs) {
	if (this != &rhs)
		type = rhs.getType();
	std::cout << YELLOW "WrongAnimal" RESET " Copy assignment operator called"
		<< std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << YELLOW "WrongAnimal" RESET " Destructor called" << std::endl;
}

/*--- MEMBER FUNCTIONS -------------------------------------------------------*/

void	WrongAnimal::makeSound() const {
	std::cout << YELLOW "* DEFINITELY NOT AN ANIMAL SOUND *" RESET << std::endl;
}

/*--- GETTER AND SETTER ------------------------------------------------------*/

std::string	WrongAnimal::getType() const { return type; }
void		WrongAnimal::setType(std::string new_type) { type = new_type; }
