/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:04:41 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/27 16:07:33 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>	// srand, rand
#include <time.h>

#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

/* Randomly instantiate A, B or C and returns the instance as a Base pointer */
Base* generate(void)
{
	std::srand((unsigned int) time(NULL));
	Base* ptr;
	std::cout << "Type ";
	switch(rand() % 3) {
		case 0:
			ptr = new A;
			std::cout << "A";
			break;
		case 1:
			ptr = new B;
			std::cout << "B";
			break;
		case 2:
			ptr = new C;
			std::cout << "C";
			break;
	}
	std::cout << " generated" << std::endl;
	return ptr;
}

/* Print the actual type of the object pointed to by p */
void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type C" << std::endl;
}

void	identify(Base& p)
{
	try {
		A a = dynamic_cast<A&>(p);
		std::cout << "Type A" << std::endl;
	} catch (std::exception& e) {}

	try {
		B b = dynamic_cast<B&>(p);
		std::cout << "Type B" << std::endl;
	} catch (std::exception& e) {}

	try {
		C c = dynamic_cast<C&>(p);
		std::cout << "Type C" << std::endl;
	} catch (std::exception& e) {}
}

int	main(void)
{
	Base*	ptr = generate();

	std::cout << "identify by pointer: ";
	identify(ptr);
	std::cout << "identify by reference: ";
	identify(*ptr);
}
