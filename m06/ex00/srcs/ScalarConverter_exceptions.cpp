/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter_exceptions.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:55:28 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/26 13:23:07 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

const char*	ScalarConverter::InvalidTypeException::what() const throw() {
	return "INVALID TYPE";
}

const char* ScalarConverter::InvalidCharException::what() const throw() {
	return "INVALID CHAR";
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
