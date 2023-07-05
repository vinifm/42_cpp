/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:44:56 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/05 16:45:42 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "../include/Animal.hpp"

class Dog : public Animal {
public:
	Dog();
	Dog(const Dog& copy);
	Dog& operator=(const Dog& rhs);
	~Dog();

	virtual void makeSound() const;

protected:
	std::string	type;
};

#endif

