/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter_print.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:09:26 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/26 15:03:51 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

void	ScalarConverter::_printConversions()
{
	if (!_precision)
		_precision = 1;
	std::cout << std::fixed << std::setprecision(_precision);
	std::cout << WHITE "Detected type: " RESET << _type << std::endl;
	_printChar();
	_printInt();
	_printFloat();
	_printDouble();
}

void	ScalarConverter::_printChar()
{
	std::cout << WHITE "char: " RESET;
	if (!_isDisplayableChar(_char))
		std::cout << "Non-displayable" << std::endl;
	else
		std::cout << _char << std::endl;
}

void	ScalarConverter::_printInt()
{
	std::cout << WHITE "int: " RESET;
	if (_intOverflow())
		std::cout << "impossible" << std::endl;
	else
		std::cout << _int << std::endl;
}

void	ScalarConverter::_printFloat()
{
	std::cout << WHITE "float: " RESET;
	if (_floatOverflow())
		std::cout << "impossible" << std::endl;
	else
		std::cout << _float << "f" << std::endl;
}

void	ScalarConverter::_printDouble()
{
	std::cout << WHITE "double: " RESET;
	std::cout << _double << std::endl;
}
