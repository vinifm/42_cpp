/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:47:55 by viferrei          #+#    #+#             */
/*   Updated: 2023/06/22 18:30:55 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _number(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int int_num) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float float_num) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) : _number(copy._number) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& assign) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &assign)
		this->setRawBits(assign.getRawBits());
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_number);
}

void	Fixed::setRawBits(int const raw) {
	_number = raw;
}
