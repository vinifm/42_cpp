/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:23:49 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/17 17:54:30 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "colors.hpp"
#include "Form.hpp"
#include <iostream>
#include <cstdlib>

class Form;

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(const std::string name, unsigned int grade);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator=(const Bureaucrat& rhs);
	~Bureaucrat();

	void	incrementGrade(unsigned int amount);
	void	decrementGrade(unsigned int amount);
	void	signForm(Form& form);

	const std::string	getName() const;
	unsigned int		getGrade() const;

private:
	const std::string	_name;
	unsigned int		_grade;

	class	GradeTooHighException: public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class	GradeTooLowException: public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs);

#endif

