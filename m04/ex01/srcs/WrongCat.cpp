/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:45:12 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/05 16:14:49 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"

/*--- CONSTRUCTORS AND DESTRUCTOR --------------------------------------------*/

WrongCat::WrongCat() : WrongAnimal() {
	setType("WrongCat");
	std::cout << "An adorable" PINK " WrongCat " RESET "stares pitifully at you."
		<< std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy) {
	*this = copy;
	std::cout << PINK "WrongCat" RESET " Copy constructor called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& rhs) {
	if (this != &rhs)
		type = rhs.getType();
	std::cout << PINK "WrongCat" RESET " Copy assignment operator called"
		<< std::endl;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << PINK "WrongCat" RESET " Destructor called" << std::endl;
}

/*--- MEMBER FUNCTIONS -------------------------------------------------------*/

void	WrongCat::makeSound() const {
	std::cout << PINK "* WrongCat meows silently *" RESET << std::endl;
}

