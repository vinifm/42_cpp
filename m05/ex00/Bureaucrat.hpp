/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:23:49 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/11 18:31:31 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#define	RESET	"\033[0m"
#define	MAGENTA	"\033[1;35m"
#define	BLUE	"\033[1;34m"
#define	WHITE	"\033[1;37m"
#define	PURPLE	"\033[1;38;5;105m"

#include <iostream>
#include <cstdlib>

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(const std::string name, unsigned int grade);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator=(const Bureaucrat& rhs);
	~Bureaucrat();

	void	incrementGrade(unsigned int amount);
	void	decrementGrade(unsigned int amount);

	const std::string	getName() const;
	int					getGrade() const;

private:
	const std::string	_name;
	int					_grade;

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

