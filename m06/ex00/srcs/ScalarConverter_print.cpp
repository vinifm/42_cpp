/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter_print.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:09:26 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/25 18:30:49 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

void	ScalarConverter::_printConversions()
{
	std::cout << std::fixed << std::setprecision(1);

	if (_doubleOverflow())
		_printImpossible();
	else {
		std::cout << "String literal: " << _str << std::endl;
		std::cout << "Detected type: " << _type << std::endl;
		std::cout << "char: " << _char << std::endl;
		std::cout << "int: " << _int << std::endl;
		std::cout << "float: " << _float << "f" << std::endl;
		std::cout << "double: " << _double << std::endl;
	}
	std::cout << std::endl;
}
