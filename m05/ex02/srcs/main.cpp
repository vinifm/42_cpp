/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:07:19 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/18 17:52:17 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

void	title(std::string msg, std::string color, size_t size);

void	testShrubberyCreationForm() {
}

int	main(void) {
	// AForm	Form;	// Should not work since AForm is abstract

	title("CONSTRUCTORS", MAGENTA, 50);
	Bureaucrat				new_guy("John", 150);
	Bureaucrat				boss("Boss", 4);
	ShrubberyCreationForm	shrub("shrubby");

	title("EXECUTE METHOD", MAGENTA, 50);
	try {
		std::cout << WHITE "Unsigned form: " RESET;
		shrub.execute(new_guy);
	} catch (std::exception& e) { std::cout << e.what() << std::endl; }

	boss.signForm(shrub);

	try {
		std::cout << WHITE "Low grade: " RESET;
		shrub.execute(new_guy);
	} catch (std::exception& e) { std::cout << e.what() << std::endl; }

	shrub.execute(boss);

	// try {
	// 	std::cout << WHITE "Unsigned form: " RESET;
	// 	shrub.execute(new_guy);
	// } catch (std::exception& e) { std::cout << e.what(); }

	title("DESTRUCTORS", MAGENTA, 50);
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


