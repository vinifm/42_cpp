/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:57:45 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/24 19:57:13 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include "../include/colors.hpp"

void	title(std::string msg, std::string color, size_t size);
void	convert(std::string str) { ScalarConverter::convert(str); }

void	testFloat()
{
	title("FLOAT CONVERSION", MAGENTA, 50);
	convert(".043f");
	convert("42f");
	convert("-402f");

	title("INVALID CASES", BLUE, 30);
	convert("4ff");
	convert("4.09.8f");
}

void	testInt()
{
	title("INT CONVERSION", MAGENTA, 50);
	convert("42");
	convert("-200");
}

int	main()
{
	// ScalarConverter	foo;	// Should not work since constructor is private;
	testFloat();
	testInt();
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
