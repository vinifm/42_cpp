/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:28:40 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/20 17:25:27 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

/*--- CONSTRUCTORS AND DESTRUCTOR --------------------------------------------*/

Intern::Intern() {
	std::cout << "An" LIME_GREEN " Intern " RESET
		<< "showed up. Did someone ask for coffee?"
		<< std::endl;
}

Intern::Intern(const Intern& copy) {
	*this = copy;
	std::cout << LIME_GREEN "Intern " RESET "Copy constructor called"
		<< std::endl;
}

Intern&	Intern::operator=(const Intern& rhs) {
	(void) rhs;
	std::cout << LIME_GREEN "Intern " RESET "Copy assignment operator called"
		<< std::endl;
	return *this;
}

Intern::~Intern() {
	std::cout << LIME_GREEN "Intern " RESET "will stay behind to clean the "
		<< "office."
		<< std::endl;
}

/*--- MEMBER FUNCTIONS -------------------------------------------------------*/

AForm*	Intern::makeForm(std::string name, std::string target) {
	size_t		index = 0;
	std::string	original_name = name;
	AForm* (Intern::*_formFuncArray[3])(std::string) = {
		&Intern::_returnPresidentialPardonForm,
		&Intern::_returnRobotomyRequestForm,
		&Intern::_returnShrubberyCreationForm
	};

	for (std::string::iterator c = name.begin(); c != name.end(); c++)
		*c = std::tolower(*c);
	for (size_t i = 0; i < formListSize; i++) {
		if (name == formList[index])
			return (this->*_formFuncArray[index])(target);
		else
			index++;
	}
	if (index == formListSize)
		std::cout << "The dummy intern says the form \""
			<< original_name << "\" does not exist!"
			<< std::endl;
	return NULL;
}

AForm*	Intern::_returnPresidentialPardonForm(std::string target) {
	return (new PresidentialPardonForm(target));
}
AForm*	Intern::_returnRobotomyRequestForm(std::string target) {
	return (new RobotomyRequestForm(target));
}
AForm*	Intern::_returnShrubberyCreationForm(std::string target) {
	return (new ShrubberyCreationForm(target));
}
