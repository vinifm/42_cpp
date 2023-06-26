/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:47:55 by viferrei          #+#    #+#             */
/*   Updated: 2023/06/26 17:38:59 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*--- CONSTRUCTORS AND DESTRUCTOR --------------------------------------------*/

Fixed::Fixed() : _rawBits(0) {
	// std::cout << "Default constructor called" << std::endl;
}

/* Converts int to corresponding fixed-point value */
Fixed::Fixed(const int int_num) {
	// std::cout << "Int constructor called" << std::endl;
	_rawBits = int_num << _fractBits;
}

/* Converts float to corresponding fixed-point value */
Fixed::Fixed(const float float_num) {
	// std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(float_num * (1 << _fractBits));
}

Fixed::Fixed(const Fixed& copy) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed& Fixed::operator=(const Fixed& assign) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &assign)
		this->setRawBits(assign.getRawBits());
	return *this;
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

/*--- MEMBER FUNCTIONS -------------------------------------------------------*/

int		Fixed::getRawBits(void) const {
	return _rawBits;
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

/*--- COMPARISON OPERATORS ---------------------------------------------------*/

bool	Fixed::operator>(const Fixed& rhs) {
	if (_rawBits > rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<(const Fixed& rhs) { return (!(*this > rhs)); }

bool	Fixed::operator>=(const Fixed& rhs) {
	if (*this == rhs)
		return true;
	return (*this > rhs);
}

bool	Fixed::operator<=(const Fixed& rhs) {
	if (*this == rhs)
		return true;
	return !(*this > rhs);
}

bool	Fixed::operator==(const Fixed& rhs) {
	if (_rawBits == rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator!=(const Fixed& rhs) { return !(*this == rhs); }

/*--- ARITHMETIC OPERATORS  --------------------------------------------------*/

Fixed	Fixed::operator+(const Fixed& rhs) const {
	Fixed	ret;
	ret.setRawBits(_rawBits + rhs.getRawBits());
	return (ret);
}

Fixed	Fixed::operator-(const Fixed& rhs) const {
	Fixed	ret;
	ret.setRawBits(_rawBits - rhs.getRawBits());
	return (ret);
}

Fixed	Fixed::operator*(const Fixed& rhs) const {
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& rhs) const {
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

/*--- INCREMENT / DECREMENT OPERATORS ----------------------------------------*/

// prefix increment
Fixed&	Fixed::operator++() {
	_rawBits++;
	return *this;
}

// postfix increment
Fixed	Fixed::operator++(int) {
	Fixed	ret(*this);
	++(*this);
	return ret;
}

// prefix decrement
Fixed&	Fixed::operator--() {
	_rawBits--;
	return *this;
}

// postfix decrement
Fixed	Fixed::operator--(int) {
	Fixed	ret(*this);
	--(*this);
	return ret;
}

/*--- MIN AND MAX FUNCTIONS --------------------------------------------------*/

Fixed&	Fixed::min(Fixed& lhs, Fixed& rhs) {
	return (lhs < rhs ? lhs : rhs);
}

const Fixed&	Fixed::min(const Fixed& lhs, const Fixed& rhs) {
	int lhs_val, rhs_val;
	lhs_val = lhs.getRawBits();
	rhs_val = rhs.getRawBits();
	return (lhs_val < rhs_val ? lhs : rhs);
}

Fixed&	Fixed::max(Fixed& lhs, Fixed& rhs) {
	return (lhs > rhs ? lhs : rhs);
}

const Fixed&	Fixed::max(const Fixed& lhs, const Fixed& rhs) {
	int lhs_val, rhs_val;
	lhs_val = lhs.getRawBits();
	rhs_val = rhs.getRawBits();
	return (lhs_val > rhs_val ? lhs : rhs);
}

/*----------------------------------------------------------------------------*/

std::ostream& operator<<(std::ostream& os, const Fixed& rhs) {
	os << rhs.toFloat();
	return os;
}
