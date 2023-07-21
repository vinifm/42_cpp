/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:07:19 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/21 20:30:51 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

void	title(std::string msg, std::string color, size_t size);

void	testFormExecute(Bureaucrat& new_guy, Bureaucrat& boss, AForm& form) {
	title("FORM EXECUTE METHOD", MAGENTA, 50);
	try {
		std::cout << WHITE "Unsigned form: " RESET;
		form.execute(new_guy);
	} catch (std::exception& e) { std::cout << e.what() << std::endl; }

	boss.signForm(form);

	try {
		std::cout << WHITE "Low grade: " RESET;
		form.execute(new_guy);
	} catch (std::exception& e) { std::cout << e.what() << std::endl; }

	form.execute(boss);
}

void	testBureaucratExecute(Bureaucrat& new_guy,
	Bureaucrat& boss,
	AForm& form)
{
	title("BUREAUCRAT EXECUTE METHOD", MAGENTA, 50);
	try {
		std::cout << WHITE "Unsigned form: " RESET;
		boss.executeForm(form);
	} catch (std::exception& e) { std::cout << e.what() << std::endl; }

	boss.signForm(form);

	try {
		std::cout << WHITE "Low grade: " RESET;
		new_guy.executeForm(form);
	} catch (std::exception& e) { std::cout << e.what() << std::endl; }

	boss.executeForm(form);
}

void	testCopies(
	PresidentialPardonForm&	ppf,
	RobotomyRequestForm&	rrf,
	ShrubberyCreationForm&	scf
) {
	title("COPIES", MAGENTA, 50);

	title("Copy Operator", BLUE, 30);
	PresidentialPardonForm	ppf_copy_op(ppf);
	ShrubberyCreationForm	scf_copy_op(scf);
	RobotomyRequestForm		rrf_copy_op(rrf);

	std::cout << std::endl
		<< ppf_copy_op << std::endl
		<< scf_copy_op << std::endl
		<< rrf_copy_op << std::endl;

	title("Copy Assignment Operator", BLUE, 30);
	PresidentialPardonForm	ppf_copy_ass;
	ShrubberyCreationForm	scf_copy_ass;
	RobotomyRequestForm		rrf_copy_ass;
	ppf_copy_ass = ppf;
	scf_copy_ass = scf;
	rrf_copy_ass = rrf;

	std::cout << std::endl
		<< ppf_copy_ass	<< std::endl
		<< scf_copy_ass	<< std::endl
		<< rrf_copy_ass	<< std::endl;

	title("Destructors", BLUE, 30);
}

int	main(void) {
	// AForm	Form;	// Should not work since AForm is abstract

	title("CONSTRUCTORS", MAGENTA, 50);
	Bureaucrat				new_guy("John", 150);
	Bureaucrat				boss("Boss", 4);
	PresidentialPardonForm	pardon("John");
	RobotomyRequestForm		robotomy("John");
	ShrubberyCreationForm	shrub("shrubby");

	testFormExecute(new_guy, boss, shrub);
	testBureaucratExecute(new_guy, boss, robotomy);
	// testCopies(pardon, robotomy, shrub);

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


