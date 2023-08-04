/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:10:19 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/04 14:45:36 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*--- STATIC VARIABLES -------------------------------------------------------*/

std::map<std::string, float>	BitcoinExchange::_dataMap;
struct tm						BitcoinExchange::_dateStruct;
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
		if (_pair.first != "\0")
			_printOutput();
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

void	BitcoinExchange::_printOutput()
{
	std::map<std::string, float>::iterator	it = _dataMap.find(_pair.first);
	if (it != _dataMap.end()) {
		std::cout << _pair.first << " => "
			<< _pair.second << " = "
			<< _pair.second * it->second
			<< std::endl;
	}
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
