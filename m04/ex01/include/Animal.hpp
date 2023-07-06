/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:44:33 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/04 19:02:26by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#define	YELLOW	"\033[1;33m"
#define	CYAN	"\033[1;36m"
#define	PINK	"\033[1;38;5;218m"
#define	PURPLE	"\033[1;38;5;105m"
#define	MAGENTA	"\033[1;35m"
#define	BLUE	"\033[1;34m"
#define	RESET	"\033[0m"

#include <iostream>

class Animal {
public:
	Animal();
	Animal(const Animal& copy);
	Animal& operator=(const Animal& rhs);
	virtual ~Animal();

	virtual void makeSound() const;

	std::string getType() const;
	void		setType(std::string new_type);

protected:
	std::string	type;
};

#endif
