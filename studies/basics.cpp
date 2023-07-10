/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:42:54 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/10 16:23:04 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.hpp"

void	input_output_stream() {
	int		num;
	std::string	str;

	std::cout << "Hello world !" << std::endl;
	std::cout << "Enter an integer and a string, respectively:" << std::endl;
	std::cin >> num >> str;
	std::cout << "You entered " << num << " and " << str << std::endl;
}

void	constructors_destructor() {
	Sample sample;					// calls default constructor
	Sample sample_copy = sample;	// calls copy constructor
	sample_copy = sample;			// calls assignment operator
}

int main() {
	// input_output_stream();
	constructors_destructor();
}
