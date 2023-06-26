/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:25:14 by viferrei          #+#    #+#             */
/*   Updated: 2023/06/26 17:45:26 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void) {
	Fixed		a;
	Fixed const	b(Fixed(5.55f) * Fixed(2));
	Fixed		c = b;
	Fixed		d(5);
	Fixed		e(2);
	Fixed const	f(142);

	std::cout << YELLOW << "a: " << RESET << a << std::endl;
	std::cout << YELLOW << "b: " << RESET << b << std::endl;
	std::cout << YELLOW << "c: " << RESET << c << std::endl;
	std::cout << YELLOW << "d: " << RESET << d << std::endl;
	std::cout << YELLOW << "e: " << RESET << e << std::endl;
	std::cout << YELLOW << "f: " << RESET << f << std::endl;

	std::cout << GREEN << "Comparison operators:" << RESET << std::endl;
	std::cout << YELLOW << "a > b: " << RESET << (a > b) << std::endl;
	std::cout << YELLOW << "a < b: " << RESET << (a < b) << std::endl;
	std::cout << YELLOW << "c >= b: " << RESET << (c >= b) << std::endl;
	std::cout << YELLOW << "c <= b: " << RESET << (c <= b) << std::endl;
	std::cout << YELLOW << "a == b: " << RESET << (a == b) << std::endl;
	std::cout << YELLOW << "c == b: " << RESET << (c == b) << std::endl;
	std::cout << YELLOW << "a != b: " << RESET << (a != b) << std::endl;

	std::cout << GREEN << "Arithmetic operators" << RESET << std::endl;
	std::cout << YELLOW << "b + d: " << RESET << (b + d) << std::endl;
	std::cout << YELLOW << "d - e: " << RESET << (d - e) << std::endl;
	std::cout << YELLOW << "d * e: " << RESET << (d * e) << std::endl;
	std::cout << YELLOW << "d / e: " << RESET << (d / e) << std::endl;

	std::cout << GREEN << "Increment / decrement operators" << RESET << std::endl;
	std::cout << YELLOW << "++a:\t" << RESET << ++a << std::endl;
	std::cout << YELLOW << "a++:\t" << RESET << a++ << std::endl;
	std::cout << YELLOW << "a:\t" << RESET << a << std::endl;
	std::cout << YELLOW << "--a:\t" << RESET << --a << std::endl;
	std::cout << YELLOW << "a--:\t" << RESET << a-- << std::endl;
	std::cout << YELLOW << "a:\t" << RESET << a << std::endl;

	std::cout << GREEN << "max and min:" << RESET << std::endl;
	std::cout << YELLOW << "min(a, d): " << RESET << Fixed::min(a, d) << std::endl;
	std::cout << YELLOW << "max(a, d): " << RESET << Fixed::max(a, d) << std::endl;
	std::cout << YELLOW << "min(b, f): " << RESET << Fixed::min(b, f) << std::endl;
	std::cout << YELLOW << "max(b, f): " << RESET << Fixed::max(b, f) << std::endl;
	std::cout << YELLOW << "max(c, b): " << RESET << Fixed::max(c, b) << std::endl;

	return 0;
}
