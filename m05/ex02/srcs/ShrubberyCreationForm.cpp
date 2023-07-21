/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:26:19 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/18 15:41:59by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

/*--- CONSTRUCTORS AND DESTRUCTOR --------------------------------------------*/

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm ((GREEN "Shrubbery Creation" RESET), 145, 137) {
		std::cout << "...It's got no target!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
	AForm ((GREEN "Shrubbery Creation" RESET), 145, 137) {
		_target = target;
		std::cout << "...It's got the target \"" << _target << "\"."
			<< std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(
	const ShrubberyCreationForm& copy) : AForm(copy) {
		std::cout << getName() << " Copy operator called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
	const ShrubberyCreationForm& rhs) {
		if (this != &rhs)
			_copyAssignmentMutator(rhs);
		std::cout << getName() << " Copy assignment operator called"
			<< std::endl;
		return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << getName() << " has been shredded" << std::endl;
}

/*--- MEMBER FUNCTIONS -------------------------------------------------------*/

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	_checkExecutePermission(executor);
	std::string		filename = _target + "_shrubbery";
	std::ofstream	outfile(filename.c_str());

	for (int i = 0; i < 3; i++) {
		outfile
			<< "             ,@@@@@@@,                  " << std::endl
			<< "     ,,,.   ,@@@@@@/@@,  .oo8888o.      " << std::endl
			<< "  ,&%&&%&&%,@@@@@/@@@@@@,8888o88/8o     " << std::endl
			<< " ,%&*%&&%&&%,@@@*@@@/@@@88o88888/88'    " << std::endl
			<< " %&&%&%&/%&&%@@*@@/ /@@@88888o88888'    " << std::endl
			<< " %&&%/ %&%&&&@@\\ V /@@' `88o8 `/88'     " << std::endl
			<< " `&%\\ ` /%&'    |.|        \\ '|8'       " << std::endl
			<< "     |o|        | |         | |         " << std::endl
			<< "     |.|        | |         | |         " << std::endl
			<< "  \\|/ ._\\//_/__/  ,\\_//__\\|/.  \\_//__/_ " << std::endl;
	}
	outfile.close();
	std::cout << "Shrubs created at " << filename << "!" << std::endl;
}
