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

std::string	ScalarConverter::_str = "";
std::string	ScalarConverter::_type = "";
int			ScalarConverter::_int = 0;
float		ScalarConverter::_float = 0;
double		ScalarConverter::_double = 0;
char		ScalarConverter::_char = 0;

/*--- CONSTRUCTORS AND DESTRUCTOR --------------------------------------------*/
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

	[x] Detect type of literal passed as parameter;
	[ ] Convert from string to actual type;
	[ ] Convert EXPLICITLY to the three other data types;

	[ ] Display message if char is non-displayable;
	[ ] Display "impossible" in case of overflow;
*/
void	ScalarConverter::convert(const std::string literal)
{
	_str = literal;
	if (_isFloat()) {
		_type = "float";
	}
	else if (_isDouble()) {
		_type = "double";
	}
	else if (_isInt()) {
		_type = "int";
		_convertInt();
	}
	else if (_isChar()) {
		_type = "char";
	}
	else if (_isPseudoLiteral()) {
		_type = "pseudo literal";
	}
	else
		throw InvalidTypeException();
	_printConversions();
}

void	ScalarConverter::_convertInt() {
	std::istringstream	iss(_str);

	iss >> _int;
	_char = static_cast<char>(_int);
	_float = static_cast<float>(_int);
	_double = static_cast<double>(_int);
}

bool	ScalarConverter::_hasSign()
{
	if (_str[0] == '+' || _str[0] == '-')
		return true;
	return false;
}

const char*	ScalarConverter::InvalidTypeException::what() const throw() {
	return "INVALID TYPE";
}
