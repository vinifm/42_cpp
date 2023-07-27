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
size_t		ScalarConverter::_precision = 0;

/*--- CONSTRUCTORS AND DESTRUCTOR --------------------------------------------*/
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& copy) { (void) copy; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {
	(void) rhs;
	return *this;
}
ScalarConverter::~ScalarConverter() {}

/*--- MEMBER FUNCTIONS -------------------------------------------------------*/

void	ScalarConverter::convert(const std::string literal)
{
	_str = literal;
	if (_isDouble())
		_convertDouble();
	else if (_isFloat())
		_convertFloat();
	else if (_isInt())
		_convertInt();
	else if (_isChar())
		_convertChar();
	else if (_isPseudoLiteral()) {
		_printPseudoLiteral();
		return ;
	}
	else
		throw InvalidTypeException();
	_printConversions();
}

void	ScalarConverter::_convertChar()
{
	std::istringstream	iss(_str);

	_type = "char";
	iss >> _char;
	_int = static_cast<int>(_char);
	_float = static_cast<float>(_char);
	_double = static_cast<double>(_char);
}

void	ScalarConverter::_convertInt()
{
	std::istringstream	iss(_str);

	_type = "int";
	if (!(iss >> _int))
		throw InvalidIntException();
	_char = static_cast<char>(_int);
	_float = static_cast<float>(_int);
	_double = static_cast<double>(_int);
}

void	ScalarConverter::_convertFloat()
{
	std::istringstream	iss(_str);

	_type = "float";
	if (!(iss >> _float))
		throw InvalidFloatException();
	_char = static_cast<char>(_float);
	_int = static_cast<int>(_float);
	_double = static_cast<double>(_float);
}

void	ScalarConverter::_convertDouble()
{
	std::istringstream	iss(_str);

	_type = "double";
	if (!(iss >> _double))
		throw InvalidDoubleException();
	_char = static_cast<char>(_double);
	_int = static_cast<int>(_double);
	_float = static_cast<float>(_double);
}

/* Add 'f' to double pseudo literal */
std::string	ScalarConverter::_floatPseudoLiteral()
{
	std::string	copy = _str;
	if (copy == "nan" || copy == "nanf")
		return "nanf";
	else if (copy.length() == 4)
		return copy.append("f");
	return _str;
}

/* Remove 'f' from a float pseudo literal */
std::string	ScalarConverter::_doublePseudoLiteral()
{
	std::string	copy = _str;
	if (copy == "nanf")
		return "nan";
	else if (copy.length() == 5)
		return copy.substr(0, copy.length() - 1);
	return _str;
}
