/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:23:49 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/10 19:12:35 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#define	RESET	"\033[0m"
#define	PURPLE	"\033[1;38;5;105m"

#include <iostream>

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(const std::string name, unsigned int grade);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator=(const Bureaucrat& rhs);
	~Bureaucrat();

	const std::string	getName() const;
	int					getGrade() const;

	void	incrementGrade(unsigned int amount);
	void	decrementGrade(unsigned int amount);

private:
	const std::string	_name;
	int					_grade;

	class	GradeTooHighException: public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Grade is too high!";
		}
	};

	class	GradeTooLowException: public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Grade is too low!";
		}
	};
};

#endif

