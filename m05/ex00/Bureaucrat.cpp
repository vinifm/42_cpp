/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:56:13 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/10 19:15:38 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*--- CONSTRUCTORS AND DESTRUCTOR --------------------------------------------*/

Bureaucrat::Bureaucrat() : _name("John"), _grade((rand() % 150) + 1) {
	std::cout << "You've just bumped into a random" PURPLE " Bureaucrat! " RESET
		<< "Let's call him John..."
		<< std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade)
	: _name(name), _grade(grade) {
	if (grade < 1)
		throw GradeTooLowException();
	else if (grade > 150)
		throw GradeTooHighException();
	std::cout << "A grumpy" PURPLE " Bureaucrat " RESET "walked into the office"
		<< std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
	*this = copy;
	std::cout << PURPLE "Bureaucrat " RESET "Copy constructor called"
		<< std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &rhs) {
	std::cout << PURPLE "Bureaucrat " RESET "Copy assignment operator called"
		<< std::endl;
	if (this != &rhs)
		_grade = rhs.getGrade(); // what about name???
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << PURPLE "Bureaucrat " RESET
		<< getName() << " is leaving the office."
		<< std::endl;
}
