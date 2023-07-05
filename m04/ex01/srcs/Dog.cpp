/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:43:43 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/05 16:26:31 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

/*--- CONSTRUCTORS AND DESTRUCTOR --------------------------------------------*/

Dog::Dog() : Animal() {
	setType("Dog");
	std::cout << "...And a huge" CYAN " Dog " RESET "comes out of a bush!"
		<< std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy) {
	*this = copy;
	std::cout << CYAN "Dog" RESET " Copy constructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& rhs) {
	if (this != &rhs)
		type = rhs.getType();
	std::cout << CYAN "Dog" RESET " Copy assignment operator called"
		<< std::endl;
	return *this;
}

Dog::~Dog() {
	std::cout << CYAN "Dog" RESET " Destructor called" << std::endl;
}

/*--- MEMBER FUNCTIONS -------------------------------------------------------*/

void	Dog::makeSound() const {
	std::cout << CYAN "* barks annoyingly *" RESET << std::endl;
}
