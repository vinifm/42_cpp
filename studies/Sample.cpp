/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:31:02 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/03 20:14:01 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.hpp"

// Constructor
Sample::Sample() : value(0), str("Hello!") {
	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Sample::Sample(const Sample &copy) {
	std::cout << "Copy constructor called" << std::endl;
	value = copy.value;
}

// Copy assignment operator
Sample&	Sample::operator=(const Sample &assign) {
	std::cout << "Assignment operator called" << std::endl;
	if (this != &assign)	// self-assignment check
		value = assign.value;
	return *this;
}

// Destructor
Sample::~Sample() {
	std::cout << "Destructor called" << std::endl;
}

// Accessor
int	Sample::getValue() const {
	return this->value;
}
