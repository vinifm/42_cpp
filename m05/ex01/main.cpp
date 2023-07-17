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

#include "Form.hpp"

void	title(std::string msg, std::string color, size_t size);

void	testFormExceptions() {
	title("FORM EXCEPTIONS", MAGENTA, 50);

	std::cout << WHITE "Sign grade too high: " RESET;
	try { Form grade_too_high("Form", 0, 50); }
	catch (std::exception& e) { std::cout << e.what() << std::endl; }

	std::cout << WHITE "Execute grade too high: " RESET;
	try { Form grade_too_high("Form", 3, 0); }
	catch (std::exception& e) { std::cout << e.what() << std::endl; }

	std::cout << WHITE "Sign grade too low: " RESET;
	try { Form grade_too_high("Form", 151, 50); }
	catch (std::exception& e) { std::cout << e.what() << std::endl; }

	std::cout << WHITE "Execute grade too low: " RESET;
	try { Form grade_too_high("Form", 3, 151); }
	catch (std::exception& e) { std::cout << e.what() << std::endl; }
}

void	testSignMethods() {
	title("SIGNING METHODS", MAGENTA, 50);
	Bureaucrat	boss("Boss", 1);
	Bureaucrat	john("John", 150);

	title("Form beSigned() method", BLUE, 30);
	Form	hard_to_sign("Day Off", 5, 1);

	std::cout << std::endl << WHITE "John tries to sign: " RESET;
	try { hard_to_sign.beSigned(john); }
	catch (std::exception& e) { std::cout << e.what() <<std::endl; }

	std::cout << WHITE "Boss signs: " RESET;
	try { hard_to_sign.beSigned(boss); }
	catch (std::exception& e) { std::cout << e.what() <<std::endl; }
	std::cout << hard_to_sign << std::endl;

	title("Bureaucrat signForm() method", BLUE, 30);
	Form	easy_to_sign("Extra Hours", 140, 130);
	std::cout << std::endl;

	john.signForm(easy_to_sign);
	boss.signForm(easy_to_sign);

	title("Destructors", BLUE, 30);
}

void	testCopies() {
	title("COPIES", MAGENTA, 50);
	Form	nameless;
	Form	copy_nameless(nameless);
	std::cout << copy_nameless << "\n" << std::endl;

	Form	coffee("Coffee", 32, 52);
	Form	copy_coffee = coffee;
	std::cout << copy_coffee << std::endl;

	title("Destructors", BLUE, 30);
}


int	main() {
	testFormExceptions();
	testSignMethods();
	testCopies();
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
