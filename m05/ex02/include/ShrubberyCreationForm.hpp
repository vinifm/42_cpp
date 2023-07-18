/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:26:25 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/18 17:32:19 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& copy);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
	~ShrubberyCreationForm();

	virtual void execute(const Bureaucrat& executor) const;
};

#endif
