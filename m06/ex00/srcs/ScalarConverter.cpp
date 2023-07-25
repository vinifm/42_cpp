/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:22:21 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/24 17:24:40by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

/*--- CONSTRUCTORS AND DESTRUCTOR --------------------------------------------*/
std::string	ScalarConverter::_str = "";
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& copy) { (void) copy; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {
	(void) rhs;
	return *this;
}
ScalarConverter::~ScalarConverter() {}

/*--- MEMBER FUNCTIONS -------------------------------------------------------*/

/*
	Take a string representation of a scalar type literal and display their
	their respective converted values.
	Supported scalar types: char, int, float, double.

	[ ] Detect type of literal passed as parameter;
	[ ] Convert from string to actual type;
	[ ] Convert EXPLICITLY to the three other data types;

	[ ] Display message if char is non-displayable;
	[ ] Display "impossible" in case of overflow;
*/
void	ScalarConverter::convert(const std::string literal)
{
	_str = literal;
	if (_isFloat()) {
		_printType("float");
	}
	else if (_isDouble()) {
		_printType("double");
	}
	else if (_isInt()) {
		_printType("int");
	}
	else
		std::cout << "INVALID TYPE" << std::endl;
}

void	ScalarConverter::_printType(const std::string type)
{
	std::cout << "Detected type: " << type << std::endl;
}

/* May have one dot, must end with 'f' */
bool	ScalarConverter::_isFloat()
{
	size_t	i = 0;
	bool	dot = false;

	if (_hasSign())
		i++;
	while (_str[i + 1] != '\0') {
		if (_str[i] != '.' && !std::isdigit(_str[i]))
			return false;
		if (_str[i] == '.' && dot)
			return false;
		if (_str[i] == '.')
			dot = true;
		i++;
	}
	if (_str[_str.length() - 1] != 'f')
		return false;
	return true;
}

/* Must have one dot */
bool	ScalarConverter::_isDouble() {
	size_t	i = 0;
	bool	dot = false;

	if (_hasSign())
		i++;
	while (_str[i] != '\0') {
		if (_str[i] != '.' && !std::isdigit(_str[i]))
			return false;
		if (_str[i] == '.' && dot)
			return false;
		if (_str[i] == '.')
			dot = true;
		i++;
	}
	return true;
}

bool	ScalarConverter::_isInt()
{
	size_t	i = 0;

	if (_hasSign())
		i++;
	while (_str[i] != '\0') {
		if (!std::isdigit(_str[i]))
			return false;
		i++;
	}
	return true;
}

bool	ScalarConverter::_hasSign() {
	if (_str[0] == '+' || _str[0] == '-')
		return true;
	return false;
}
