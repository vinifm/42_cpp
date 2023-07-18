/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:18:56 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/17 18:07:48y viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "../include/colors.hpp"
#include "../include/Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm {
public:
	AForm();
	AForm(const std::string name,
		const unsigned int signGrade,
		const unsigned int execGrade);
	AForm(const AForm& copy);
	AForm& operator=(const AForm& rhs);
	virtual ~AForm();

	void	beSigned(const Bureaucrat& bureaucrat);

	const std::string	getName() const;
	bool				getSigned() const;
	unsigned int		getSignGrade() const;
	unsigned int		getExecGrade() const;

private:
	const std::string	_name;
	bool				_signed;
	const unsigned int	_signGrade;
	const unsigned int	_execGrade;

	void	_checkGrade(const unsigned int grade);

	class	GradeTooHighException: public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class	GradeTooLowException: public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
