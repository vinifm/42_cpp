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

#ifndef AFORM_HPP
# define AFORM_HPP

#include "../include/colors.hpp"
#include "../include/Bureaucrat.hpp"
#include <iostream>
#include <stdlib.h>	// srand, rand
#include <time.h>

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

	bool			beSigned(const Bureaucrat& bureaucrat);
	virtual void	execute(const Bureaucrat& executor) const = 0;

	const std::string	getName() const;
	bool				getSigned() const;
	unsigned int		getSignGrade() const;
	unsigned int		getExecGrade() const;
	std::string			getTarget() const;

protected:
	std::string	_target;
	void		_checkExecutePermission(const Bureaucrat& executor) const;
	bool		_checkSigned() const;
	void		_copyAssignmentMutator(const AForm& rhs);

private:
	const std::string	_name;
	bool				_signed;
	const unsigned int	_signGrade;
	const unsigned int	_execGrade;

	void	_checkGrade(const unsigned int grade);

	class	GradeTooHighException: public std::exception {
		public: virtual const char* what() const throw(); };

	class	GradeTooLowException: public std::exception {
		public: virtual const char* what() const throw(); };

	class	FormNotSignedException: public std::exception {
		public: virtual const char* what() const throw(); };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
