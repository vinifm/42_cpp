/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:10:19 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/03 19:07:16 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*--- CONSTRUCTORS AND DESTRUCTOR --------------------------------------------*/

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {}
BitcoinExchange::~BitcoinExchange() {}

/*--- MEMBER FUNCTIONS -------------------------------------------------------*/

void	BitcoinExchange::execute(std::ifstream& inputFile)
{
	std::string	line;

	_saveCsvIntoMap();
	std::getline(inputFile, line);
	while (std::getline(inputFile, line)) {

	}
}

void	BitcoinExchange::_saveCsvIntoMap()
{
	std::ifstream	file;
	std::string		line;
	std::string		date;

	file.open("data.csv", std::ifstream::in);
	if (!file.is_open())
		throw FailedToOpenException();
	std::getline(file, line);
	while (std::getline(file, line)) {
		std::istringstream	iss(line);

		std::getline(iss, date, ',');
		_dataMap[date] =
	}
}

/*--- EXCEPTIONS -------------------------------------------------------------*/

const char*	BitcoinExchange::FailedToOpenException::what() const throw() {
	return	"Failed to open CSV file";
}
