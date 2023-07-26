/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter_print.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:09:26 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/26 14:18:20 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

void	ScalarConverter::_printConversions()
{
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "Detected type: " << _type << std::endl;
	_printChar();
	_printInt();
	_printFloat();
	_printDouble();
	std::cout << std::endl;
}

void	ScalarConverter::_printChar()
{
	std::cout << "char: ";
	if (!_isDisplayableChar(_char))
		std::cout << "Non-displayable" << std::endl;
	else
		std::cout << _char << std::endl;
}

void	ScalarConverter::_printInt()
{
	std::cout << "int: ";
	if (_intOverflow())
		std::cout << "impossible" << std::endl;
	else
		std::cout << _int << std::endl;
}

void	ScalarConverter::_printFloat()
{
	std::cout << "float: ";
	if (_floatOverflow())
		std::cout << "impossible" << std::endl;
	else
		std::cout << _float << "f" << std::endl;
}

void	ScalarConverter::_printDouble()
{
	std::cout << "double: ";
	std::cout << _double << std::endl;
}
