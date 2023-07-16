/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:18:56 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/16 12:37:42 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "colors.hpp"
#include <iostream>

class Form {
public:
	Form();
	Form(const std::string name);
	Form(const Form& copy);
	Form& operator=(const Form& rhs);
	~Form();

	const std::string	getName();
	bool				getSigned();
	const unsigned int	getSignGrade();
	const unsigned int	getExecGrade();

private:
	const std::string	_name;
	bool				_signed;
	const unsigned int	_signGrade;
	const unsigned int	_execGrade;

	class	GradeTooHighException: public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class	GradeTooLowException: public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& rhs);

#endif
