/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:31:02 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/10 16:22:45 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.hpp"

/*--- CONSTRUCTORS AND DESTRUCTOR --------------------------------------------*/

Sample::Sample() {
	std::cout << "Sample Default constructor called" << std::endl;
}

Sample::Sample(const Sample &copy) {
	*this = copy;
	std::cout << "Sample Copy constructor called" << std::endl;
}

Sample&	Sample::operator=(const Sample &rhs) {
	std::cout << "Sample Copy assignment operator called" << std::endl;
	if (this != &rhs)
		// value = rhs.value;
	return *this;
}

Sample::~Sample() {
	std::cout << "Sample Destructor called" << std::endl;
}
