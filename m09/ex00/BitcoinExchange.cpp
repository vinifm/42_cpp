/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:10:19 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/03 20:58:09 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*--- STATIC VARIABLES -------------------------------------------------------*/

std::map<std::string, float>	BitcoinExchange::_dataMap;

/*--- CONSTRUCTORS AND DESTRUCTOR --------------------------------------------*/

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) { (void)copy; }
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
	(void)rhs;
	return *this;
}
BitcoinExchange::~BitcoinExchange() {}

/*--- MEMBER FUNCTIONS -------------------------------------------------------*/

void	BitcoinExchange::execute(std::ifstream& inputFile)
{
	std::string	line;

	_saveCsvIntoMap();
	std::getline(inputFile, line);
	while (std::getline(inputFile, line)) {
		_validateLine(line);
	}
}

std::pair<std::string, float>	BitcoinExchange::_validateLine(std::string line)
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

std::string	BitcoinExchange::_validateDate(std::string date)
{
	struct tm	timeStruct;
	const char*	timePtr = strptime(date.c_str(), "%Y-%m-%d", &timeStruct);

	if (timePtr == NULL || *timePtr != '\0') {
		_errorMsg("bad input", date);
		return "\0";
	}
	return date;
}

float BitcoinExchange::_validateValue(std::string valueStr)
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

void	BitcoinExchange::_saveCsvIntoMap()
{
	std::ifstream	file;
	std::string		line;
	float			exchangeRate;

	file.open("data.csv", std::ifstream::in);
	if (!file.is_open())
		throw FailedToOpenException();
	std::getline(file, line);
	while (std::getline(file, line)) {
		size_t				commaPosition = line.find(",");
		std::string			date = line.substr(0, commaPosition);
		std::istringstream	afterComma(line.substr(commaPosition + 1));

		afterComma >> exchangeRate;
		_dataMap[date] = exchangeRate;
	}
}

void	BitcoinExchange::_errorMsg(std::string desc, std::string input)
{
	std::cerr << RED "Error: " RESET << desc << " => " << input
		<< std::endl;
}

/*--- EXCEPTIONS -------------------------------------------------------------*/

const char*	BitcoinExchange::FailedToOpenException::what() const throw() {
	return	"Failed to open CSV file";
}
