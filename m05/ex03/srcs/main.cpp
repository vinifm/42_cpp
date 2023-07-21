/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:07:19 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/21 20:28:36 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

void	title(std::string msg, std::string color, size_t size);

int	main(void) {
	title("CONSTRUCTORS", MAGENTA, 50);
	Intern	random_intern;
	AForm*	presidential_pardon;
	AForm*	robotomy_request;
	AForm*	shrubbery_creation;
	AForm*	nonexistent_form;

	title("MAKE FORM", MAGENTA, 50);
	presidential_pardon = random_intern.makeForm("Presidential Pardon", "John");
	robotomy_request = random_intern.makeForm("robotomy request", "Jessica");
	shrubbery_creation = random_intern.makeForm("shrubbery Creation", "Park");
	nonexistent_form = random_intern.makeForm("Vacation", "Now");

	title("DESTRUCTORS", MAGENTA, 50);
	delete presidential_pardon;
	delete robotomy_request;
	delete shrubbery_creation;
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
