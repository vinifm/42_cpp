/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter_exceptions.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:13:30 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/26 15:00:01 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

bool	ScalarConverter::_intOverflow()
{
	if (_double < std::numeric_limits<int>::min()
		|| _double > std::numeric_limits<int>::max())
		return true;
	return false;
}
bool	ScalarConverter::_floatOverflow()
{
	double	float_max = std::numeric_limits<float>::max();
	if (_double < -float_max || _double > float_max)
		return true;
	return false;
}

const char*	ScalarConverter::InvalidTypeException::what() const throw() {
	return "INVALID TYPE";
}

const char* ScalarConverter::InvalidIntException::what() const throw() {
	return "INVALID INT";
}

const char* ScalarConverter::InvalidFloatException::what() const throw() {
	return "INVALID FLOAT";
}

const char* ScalarConverter::InvalidDoubleException::what() const throw() {
	return "INVALID DOUBLE";
}
