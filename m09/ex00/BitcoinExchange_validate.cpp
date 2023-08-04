/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange_validate.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:28:13 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/04 17:49:11 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::pair<std::string, float>	BitcoinExchange::_validateLine(
	const std::string& line)
{
	size_t		delimPos = line.find(" | ");
	std::pair<std::string, float>	pair;

	if (delimPos == std::string::npos) {
		_errorMsg("delimiter not found", line);
		pair.first = "\0";
		pair.second = -1;
	}
	else {
		pair.first = _validateDate(line.substr(0, delimPos));
		pair.second = _validateValue(line.substr(delimPos + 3));
	}
	return pair;
}

std::string	BitcoinExchange::_validateDate(const std::string& dateStr)
{
	if (_getDateTime(dateStr) == -1)
		return "\0";
	return dateStr;
}

float BitcoinExchange::_validateValue(const std::string& valueStr)
{
	std::istringstream	iss(valueStr);
	float				value;

	if (!(iss >> value))
		_errorMsg("bad input", valueStr);
	else if (value < 0)
		_errorMsg("not a positive number", valueStr);
	else if (value > 1000)
		_errorMsg("number too large", valueStr);
	else
		return value;
	return -1;
}

void	BitcoinExchange::_errorMsg(std::string desc, std::string input)
{
	std::cerr << RED "Error: " RESET << desc << " => " << input
		<< std::endl;
}
