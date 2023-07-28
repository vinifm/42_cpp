/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:06:52 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/28 17:30:09by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <stdlib.h>	// srand, rand

#define	RESET	"\033[0m"
#define	MAGENTA	"\033[1;35m"

void	title(std::string msg, std::string color, size_t size);

void	testIntArray()
{
	title("INT ARRAY", MAGENTA, 50);
	size_t	size = 5;

	Array<int>	empty;
	Array<int>	arr(size);
	Array<int>	copy(size);

	std::cout << "empty array size: " << empty.size() << std::endl;
	std::cout << "1st array: ";
	for (size_t i = 0; i < size; i++) {
		arr[i] = i;
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl << "2nd array: ";
	displayArray(copy);
	std::cout << "2nd array after copy assignment: ";
	copy = arr;
	displayArray(copy);
	std::cout << "1st array changed: ";
	arr[0] = 42;
	displayArray(arr);
	std::cout << "2nd array: ";
	displayArray(copy);
	std::cout << "Index out of bounds: ";
	try { arr[10]; }
	catch (std::exception& e) {std::cout << e.what() << std::endl; }
	copy = empty;
	displayArray(copy);
}

void	testStringArray()
{
	title("STRING ARRAY", MAGENTA, 50);
	Array<std::string>	arr(3);
	Array<std::string>	copy(3);

	arr[0] = "Mary had";
	arr[1] = "a little";
	arr[2] = "lamb";

	displayArray(copy);
	copy = arr;
	displayArray(arr);
	displayArray(copy);
}

int	main(void)
{
	testIntArray();
	testStringArray();
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
