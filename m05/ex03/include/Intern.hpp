/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:24:29 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/20 16:56:37 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

static const std::string	formList[3] = {
	"presidential pardon",
	"robotomy request",
	"shrubbery creation"
};
static const size_t	formListSize = sizeof(formList) / sizeof(formList[0]);

class Intern {
public:
	Intern();
	Intern(const Intern& copy);
	Intern& operator=(const Intern& rhs);
	~Intern();

	AForm*	makeForm(std::string name, std::string target);

private:
	AForm*	_returnPresidentialPardonForm(std::string target);
	AForm*	_returnRobotomyRequestForm(std::string target);
	AForm*	_returnShrubberyCreationForm(std::string target);
};

#endif
