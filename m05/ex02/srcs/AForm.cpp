/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:27:55 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/21 20:12:54 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

/*--- CONSTRUCTORS AND DESTRUCTOR --------------------------------------------*/

AForm::AForm() :
	_target("NO_TARGET"),
	_name("Blank"),
	_signed(false),
	_signGrade(150),
	_execGrade(150)
{
	std::cout << "You've found a blank" YELLOW " AForm. " RESET
		<< "It's pretty useless."
		<< std::endl;
}

AForm::AForm(
	const std::string name,
	const unsigned int signGrade,
	const unsigned int execGrade
	) :
	_target("NO_TARGET"),
	_name(name),
	_signed(false),
	_signGrade(signGrade),
	_execGrade(execGrade)
{
	_checkGrade(signGrade);
	_checkGrade(execGrade);
	std::cout << YELLOW "AForm " RESET << "\""
		<< getName() << "\" with sign grade "
		<< getSignGrade() << " and execute grade "
		<< getExecGrade() << " is delivered to your desk."
		<< std::endl;
}

AForm::AForm(const AForm& copy) :
	_target(copy.getTarget()),
	_name(copy.getName()),
	_signed(copy.getSigned()),
	_signGrade(copy.getSignGrade()),
	_execGrade(copy.getExecGrade())
{
		std::cout << YELLOW "AForm " RESET "Copy constructor called"
			<< std::endl;
}

AForm&	AForm::operator=(const AForm &rhs) {
	std::cout << YELLOW "AForm " RESET "Copy assignment operator called"
		<< std::endl;
	if (this != &rhs)
		_copyAssignmentMutator(rhs);
	return *this;
}

AForm::~AForm() {
	std::cout << YELLOW "AForm " RESET
		<< getName() << " has been shredded."
		<< std::endl;
}

/*--- MEMBER FUNCTIONS -------------------------------------------------------*/

/* Change form status to signed if Bureaucrat grade is high enough */
bool	AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > getSignGrade())
		throw GradeTooLowException();
	if (!_checkSigned()) {
		_signed = true;
		return true;
	}
	return false;
}

bool	AForm::_checkSigned() const {
	if (getSigned()) {
		std::cout << "Save your ink! "
			<< getName() << " is already signed."
			<< std::endl;
		return true;
	}
	return false;
}

void	AForm::_checkGrade(const unsigned int grade) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

/* Check if form is signed and if bureaucrat grade is high enough */
void	AForm::_checkExecutePermission(const Bureaucrat& executor) const {
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
}

/*--- ACCESSORS --------------------------------------------------------------*/

const std::string	AForm::getName() const { return _name; }
bool				AForm::getSigned() const { return _signed; }
unsigned int		AForm::getSignGrade() const { return _signGrade; }
unsigned int		AForm::getExecGrade() const { return _execGrade; }
std::string			AForm::getTarget() const { return _target; }

/*--- MUTATORS ---------------------------------------------------------------*/

void	AForm::_copyAssignmentMutator(const AForm& rhs) {
	_target = rhs.getTarget();
	_signed = rhs.getSigned();
	const_cast<std::string&>(_name) = rhs.getName();
	const_cast<unsigned int&>(_signGrade) = rhs.getSignGrade();
	const_cast<unsigned int&>(_execGrade) = rhs.getExecGrade();
}

/*--- EXCEPTIONS -------------------------------------------------------------*/

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Execution denied: Form is not signed!";
}

/*--- INSERTION OPERATOR OVERLOAD --------------------------------------------*/

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	std::string signed_status = "unsigned";

	if (form.getSigned())
		signed_status = "signed";
	os << signed_status << " form \""
		<< form.getName() << "\" has sign grade "
		<< form.getSignGrade() << " and execute grade "
		<< form.getExecGrade();
	return os;
}
