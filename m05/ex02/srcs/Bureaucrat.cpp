/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:56:13 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/19 17:41:06 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

/*--- CONSTRUCTORS AND DESTRUCTOR --------------------------------------------*/

Bureaucrat::Bureaucrat() : _name("John"), _grade((rand() % 150) + 1) {
	std::cout << "You've just bumped into a random" PURPLE " Bureaucrat! " RESET
		<< "Let's call him John..."
		<< std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade)
	: _name(name), _grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Grumpy" PURPLE " Bureaucrat " RESET
		<< getName() << " with grade "
		<< getGrade() << " walked into the office."
		<< std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy.getName()) {
	*this = copy;
	std::cout << PURPLE "Bureaucrat " RESET "Copy constructor called"
		<< std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs) {
	std::cout << PURPLE "Bureaucrat " RESET "Copy assignment operator called"
		<< std::endl;
	if (this != &rhs)
		_grade = rhs.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << PURPLE "Bureaucrat " RESET
		<< getName() << " is leaving the office."
		<< std::endl;
}

/*--- MEMBER FUNCTIONS -------------------------------------------------------*/

void	Bureaucrat::incrementGrade(unsigned int amount) {
	if (getGrade() - amount < 1)
		throw GradeTooHighException();
	else {
		_grade = getGrade() - amount;
		std::cout << getName() << "'s grade is incremented to "
			<< getGrade()
			<< std::endl;
	}
}

void	Bureaucrat::decrementGrade(unsigned int amount) {
	if (getGrade() + amount > 150)
		throw GradeTooLowException();
	else {
		_grade = getGrade() + amount;
		std::cout << getName() << "'s grade is decremented to "
			<< getGrade()
			<< std::endl;
	}
}

void	Bureaucrat::signForm(AForm& form) {
	try {
		if (form.beSigned(*this)) {
			std::cout << PURPLE << "Bureaucrat " RESET
				<< getName() << " signed form "
				<< form.getName()
				<< std::endl;
		}
	} catch (std::exception& e) {
		std::cout << PURPLE "Bureaucrat " RESET
			<< getName() << " could not sign form "
			<< form.getName() << " because "
			<< e.what()
			<< std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm& form) {
	try {
		form.execute(*this);
		std::cout << PURPLE << "Bureaucrat " RESET
			<< getName() << " executed form "
			<< form.getName()
			<< std::endl;
	} catch (std::exception& e) {
		std::cout << PURPLE "Bureaucrat " RESET
			<< getName() << " could not execute form "
			<< form.getName() << " because "
			<< e.what()
			<< std::endl;
	}
}

/*--- ACCESSORS --------------------------------------------------------------*/

const std::string	Bureaucrat::getName() const { return _name; }
unsigned int		Bureaucrat::getGrade() const { return _grade; }

/*--- EXCEPTIONS -------------------------------------------------------------*/

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat's grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat's grade is too low!";
}

/*--- INSERTION OPERATOR OVERLOAD --------------------------------------------*/

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs) {
	os << rhs.getName() << ", bureaucrat grade " <<  rhs.getGrade() << ".";
	return os;
}
