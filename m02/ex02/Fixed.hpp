/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:47:57 by viferrei          #+#    #+#             */
/*   Updated: 2023/06/27 16:59:55 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

#define YELLOW	"\033[1;33m"
#define GREEN	"\033[1;32m"
#define	RESET	"\033[0m"

class Fixed {
public:
	Fixed();
	Fixed(const int int_num);
	Fixed(const float float_num);
	Fixed(const Fixed& copy);
	Fixed& operator=(const Fixed& assign);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	// Comparison operators
	bool	operator>(const Fixed& rhs);
	bool	operator<(const Fixed& rhs);
	bool	operator>=(const Fixed& rhs);
	bool	operator<=(const Fixed& rhs);
	bool	operator==(const Fixed& rhs);
	bool	operator!=(const Fixed& rhs);

	// Arithmetic operators
	Fixed	operator+(const Fixed& rhs) const;
	Fixed	operator-(const Fixed& rhs) const;
	Fixed	operator*(const Fixed& rhs) const;
	Fixed	operator/(const Fixed& rhs) const;

	// Increment/decrement operators
	Fixed&	operator++();		// prefix increment
	Fixed	operator++(int);	// postfix increment
	Fixed&	operator--();		// prefix decrement
	Fixed	operator--(int);	// postfix decrement

	static Fixed&	min(Fixed& lhs, Fixed& rhs);
	static const Fixed&	min(const Fixed& lhs, const Fixed& rhs);
	static Fixed&	max(Fixed& lhs, Fixed& rhs);
	static const Fixed&	max(const Fixed& lhs, const Fixed& rhs);

private:
	int					_rawBits;
	static const int	_fractBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& rhs);

#endif
