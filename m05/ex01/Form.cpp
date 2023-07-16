/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:27:55 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/16 12:37:35 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*--- CONSTRUCTORS AND DESTRUCTOR --------------------------------------------*/

Form::Form() : _name("Nameless") {
	std::cout << "An empty-headed office worker forgot to name this"
		<< YELLOW " Form." RESET
		<< std::endl;
}

Form::Form(const std::string name) : _name(name) ß{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Grumpy" YELLOW " Form " RESET
		<< getName() << " with grade "
		<< getGrade() << " walked into the office."
		<< std::endl;
}

Form::Form(const Form &copy) : _name(copy.getName()) {
	*this = copy;
	std::cout << YELLOW "Form " RESET "Copy constructor called"
		<< std::endl;
}

Form&	Form::operator=(const Form &rhs) {
	std::cout << YELLOW "Form " RESET "Copy assignment operator called"
		<< std::endl;
	if (this != &rhs)
		_grade = rhs.getGrade();
	return *this;
}

Form::~Form() {
	std::cout << YELLOW "Form " RESET
		<< getName() << " is leaving the office."
		<< std::endl;
}
