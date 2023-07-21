/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:50:36 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/21 20:15:16 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

/*--- CONSTRUCTORS AND DESTRUCTOR --------------------------------------------*/

RobotomyRequestForm::RobotomyRequestForm() :
	AForm ((CYAN "Robotomy Request" RESET), 72, 45) {
		std::cout << "...It's got no target!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
	AForm ((CYAN "Robotomy Request" RESET), 72, 45) {
		_target = target;
		std::cout << "...It's got the target \"" << _target << "\"."
			<< std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(
	const RobotomyRequestForm& copy) : AForm(copy) {
		std::cout << getName() << " Copy operator called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(
	const RobotomyRequestForm& rhs) {
		if (this != &rhs)
			_copyAssignmentMutator(rhs);
		std::cout << getName() << " Copy assignment operator called"
			<< std::endl;
		return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << getName() << " has been shredded" << std::endl;
}

/*--- MEMBER FUNCTIONS -------------------------------------------------------*/

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	_checkExecutePermission(executor);
	std::cout << "VrrRRrrr vrrrRRRrr VrrrRrrRrvrr... ";
	if (rand() % 2) {
		std::cout << _target
			<< " has been successfully robotomized!"
			<< std::endl;
	}
	else {
		std::cout << _target
			<< "'s robotomy has failed. Wanna try again?"
			<< std::endl;
	}
}
