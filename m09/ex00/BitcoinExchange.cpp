/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:10:19 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/05 22:13:57 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*--- STATIC VARIABLES -------------------------------------------------------*/

std::map<std::string, float>	BitcoinExchange::_dataMap;
std::pair<std::string, float>	BitcoinExchange::_pair;

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
		_pair = _validateLine(line);
		if (_pair.first != "\0" && _pair.second != -1)
			_findDate();
	}
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

/*
	Find and print corresponding or closest lower date between input and map
	database
*/
void	BitcoinExchange::_findDate()
{
	std::map<std::string, float>::iterator	it = _dataMap.find(_pair.first);
	std::time_t	inputDate = _getDateTime(_pair.first);
	std::map<std::string, float>::iterator	lowerDate = _dataMap.begin();
	std::time_t	mapDate;

	if (it != _dataMap.end()) {
		_printOutput(it);
		return ;
	}
	for (it = _dataMap.begin(); it != _dataMap.end(); ++it) {
		mapDate = _getDateTime(it->first);
		if (inputDate > mapDate)
			lowerDate = it;
		else
			break ;
	}
	_printOutput(lowerDate);
}

void	BitcoinExchange::_printOutput(std::map<std::string, float>::iterator it)
{
	std::cout << _pair.first << " => "
		<< _pair.second << " = "
		<< _pair.second * it->second
		<< std::endl;
}

std::time_t	BitcoinExchange::_getDateTime(const std::string& dateStr)
{
	std::tm 	tm = {};
	const char*	timePtr = strptime(dateStr.c_str(), "%Y-%m-%d", &tm);
	std::time_t	dateTime;

	if (timePtr == NULL || *timePtr != '\0') {
		_errorMsg("invalid date", dateStr);
		return -1;
	}
	dateTime = std::mktime(&tm);
	if (dateTime == -1)
		_errorMsg("Failed to convert to std::time_t", dateStr);
	return dateTime;
}

void	BitcoinExchange::_iterateMap(std::map<std::string, float>& map)
{
	for (std::map<std::string, float>::iterator it = map.begin();
		it != map.end();
		++it)
	{
		std::cout << "date: " << it->first << " rate: " << it->second
			<< std::endl;
	}
}

/*--- EXCEPTIONS -------------------------------------------------------------*/

const char*	BitcoinExchange::FailedToOpenException::what() const throw() {
	return	"Failed to open CSV file";
}
