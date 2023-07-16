/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:19:57 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/11 18:11:20by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	title(std::string msg, std::string color);

int	main() {
	std::srand((unsigned int) time(NULL));
	title("CONSTRUCTORS", MAGENTA);
	Bureaucrat	john;
	Bureaucrat	jim("Jim", 150);
	Bureaucrat	copyJim(jim);

	title("INSERTION OPERATOR", MAGENTA);
	std::cout << john << std::endl;
	std::cout << jim << std::endl;
	std::cout << copyJim << std::endl;

	title("EXCEPTIONS", MAGENTA);
	try { Bureaucrat james("James", 0); }
	catch (const std::exception& e) { std::cout << e.what() << std::endl; }
	try { Bureaucrat Joel("Joel", 151); }
	catch (const std::exception& e) { std::cout << e.what() << std::endl; }

	title("INCREMENT AND DECREMENT METHODS", MAGENTA);
	jim.incrementGrade(50);
	jim.decrementGrade(5);

	std::cout << std::endl << WHITE "Method exceptions:" RESET << std::endl;
	try { jim.decrementGrade(46); }
	catch (const std::exception& e) { std::cout << e.what() << std::endl; }
	try { jim.incrementGrade(105); }
	catch (const std::exception& e) { std::cout << e.what() << std::endl; }

	title("DESTRUCTORS", MAGENTA);
	return 0;
}

/* Print formatted title */
void	title(std::string msg, std::string color) {
	size_t	chars_left = 50 - msg.size();

	std::cout << std::endl << color << "/*--- " << msg << " ";
	for (size_t i = 0; i < chars_left; i++)
		std::cout << "-";
	std::cout << "*/" << RESET << std::endl;
}
