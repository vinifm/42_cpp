/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:47:55 by viferrei          #+#    #+#             */
/*   Updated: 2023/06/23 17:11:09 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

/* Converts int to corresponding fixed-point value */
Fixed::Fixed(const int int_num) {
	std::cout << "Int constructor called" << std::endl;
	_rawBits = int_num << _fractBits;
}

/* Converts float to corresponding fixed-point value */
Fixed::Fixed(const float float_num) {
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(float_num * (1 << _fractBits));
}

Fixed::Fixed(const Fixed& copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
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
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw) {
	_rawBits = raw;
}

float	Fixed::toFloat(void) const {
	return (static_cast<float>(_rawBits) / (1 << _fractBits));
}

int		Fixed::toInt(void) const {
	return (_rawBits >> _fractBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& rhs) {
	os << rhs.toFloat();
	return os;
}
