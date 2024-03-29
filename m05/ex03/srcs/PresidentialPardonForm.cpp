/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:15:40 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/21 20:14:36 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

/*--- CONSTRUCTORS AND DESTRUCTOR --------------------------------------------*/

PresidentialPardonForm::PresidentialPardonForm() :
	AForm ((ORANGE "Presidential Pardon" RESET), 25, 5) {
		std::cout << "...It's got no target!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) :
	AForm ((ORANGE "Presidential Pardon" RESET), 25, 5) {
		_target = target;
		std::cout << "...It's got the target \"" << _target << "\"."
			<< std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm& copy) : AForm(copy) {
		std::cout << getName() << " Copy operator called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(
	const PresidentialPardonForm& rhs) {
		if (this != &rhs)
			_copyAssignmentMutator(rhs);
		std::cout << getName() << " Copy assignment operator called"
			<< std::endl;
		return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << getName() << " has been shredded" << std::endl;
}

/*--- MEMBER FUNCTIONS -------------------------------------------------------*/

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	_checkExecutePermission(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox!"
		<< std::endl;
}
