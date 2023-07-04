/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:40:44 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/04 19:24:21 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

/*--- CONSTRUCTORS AND DESTRUCTOR --------------------------------------------*/

Cat::Cat() : Animal() {
	setType("Cat");
	std::cout << "A grumpy" PINK " Cat " RESET "stares judgmentally at you >:("
		<< std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy) {
	*this = copy;
	std::cout << PINK "Cat" RESET " Copy constructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& rhs) {
	if (this != &rhs)
		type = rhs.getType();
	std::cout << PINK "Cat" RESET " Copy assignment operator called"
		<< std::endl;
	return *this;
}

Cat::~Cat() {
	std::cout << PINK "Cat" RESET " Destructor called" << std::endl;
}

/*--- MEMBER FUNCTIONS -------------------------------------------------------*/

void	Cat::makeSound() const {
	std::cout << PINK "* meows diabolically *" RESET << std::endl;
}

