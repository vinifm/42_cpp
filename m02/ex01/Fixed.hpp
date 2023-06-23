/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:47:57 by viferrei          #+#    #+#             */
/*   Updated: 2023/06/23 16:40:48 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

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


private:
	int					_rawBits;
	static const int	_fractBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& rhs);

#endif
