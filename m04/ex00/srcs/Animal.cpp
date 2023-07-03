/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:28:37 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/03 20:07:04by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

/*--- CONSTRUCTORS AND DESTRUCTOR --------------------------------------------*/

Animal::Animal() : type("Animal") {
	std::cout << YELLOW "Animal" RESET " Default constructor called"
		<< std::endl;
}

Animal::Animal(const Animal& copy) {
	*this = copy;
	std::cout << YELLOW "Animal" RESET " Copy constructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& rhs) {
	if (this != &rhs)
		type = rhs.getType();
	return *this;
	std::cout << YELLOW "Animal" RESET " Copy assignment operator called"
		<< std::endl;
}

Animal::~Animal() {
	std::cout << YELLOW "Animal" RESET " Destructor called" << std::endl;
}

/*--- MEMBER FUNCTIONS -------------------------------------------------------*/

void	Animal::makeSound() const {
	std::cout << "* UNRECOGNIZABLE ANIMAL NOIZE *" << std::endl;

}

/*--- GETTERS ----------------------------------------------------------------*/

std::string Animal::getType() const { return type; }
