/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter_detect.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:42:47 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/26 13:21:26 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

/* May have one dot, must end with 'f' */
bool	ScalarConverter::_isFloat()
{
	size_t	i = 0;
	bool	dot = false;

	if (_hasSign())
		i++;
	while (_str[i + 1] != '\0') {
		if (_str[i] != '.' && !_isdigit(_str[i]))
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
bool	ScalarConverter::_isDouble()
{
	size_t	i = 0;
	bool	dot = false;

	if (!_str[0])
		return false;
	if (_hasSign())
		i++;
	while (_str[i] != '\0') {
		if (_str[i] != '.' && !_isdigit(_str[i]))
			return false;
		if (_str[i] == '.' && dot)
			return false;
		if (_str[i] == '.')
			dot = true;
		i++;
	}
	if (!dot)
		return false;
	return true;
}

bool	ScalarConverter::_isInt()
{
	size_t	i = 0;

	if (!_str[0])
		return false;
	if (_hasSign())
		i++;
	while (_str[i] != '\0') {
		if (!_isdigit(_str[i]))
			return false;
		i++;
	}
	return true;
}

/* Detect only displayable characters */
bool	ScalarConverter::_isChar()
{
	if ((_str.length() == 1)
		&& (_str[0] >= '!' && _str[0] <= '~'))
		return true;
	return false;
}

bool	ScalarConverter::_isPseudoLiteral() {
	if (_str == "+inf"
		|| _str == "-inf"
		|| _str == "nan"
		|| _str == "+inff"
		|| _str == "-inff"
		|| _str == "nanf")
		return true;
	return false;
}

bool	ScalarConverter::_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (true);
	else
		return (false);
}

bool	ScalarConverter::_isDisplayableChar(char c)
{
	if (c >= '!' && c <= '~')
		return true;
	return false;
}
