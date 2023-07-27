/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:12:12 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/27 20:27:18by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

void	title(std::string msg, std::string color, size_t size);

int	main(void)
{
	title("SWAP", MAGENTA, 50);
	int	a = 2;
	int	b = 3;

	std::cout << "Values before swap:" << std::endl
		<< "a = " << a << ", b = " << b << std::endl
		<< "Values after swipe:" << std::endl;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;

	title("MAX AND MIN", MAGENTA, 50);
	std::cout << "a = " << a << ", b = " << b << std::endl
		<< "min(a, b) = " << ::min(a, b) << std::endl
		<< "max(a, b) = " << ::max(a, b) << "\n" << std::endl;

	std::string	c = "chaine1";
	std::string	d = "chaine2";

	std::cout << "c = " << c << ", d = " << d << std::endl
		<< "min(c, d) = " << ::min(c, d) << std::endl
		<< "max(c, d) = " << ::max(c, d) << std::endl;

	return 0;
}

/* Print formatted title */
void	title(std::string msg, std::string color, size_t size) {
	if (size < msg.size())
		size = msg.size();
	size_t	chars_left = size - msg.size();

	std::cout << std::endl << color << "/*--- " << msg << " ";
	for (size_t i = 0; i < chars_left; i++)
		std::cout << "-";
	std::cout << "*/" << RESET << std::endl;
}



