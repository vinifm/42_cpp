/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:10:46 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/04 17:53:57 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>	// ifstream
#include <sstream>	// istringstream
#include <ctime>
#include <limits.h>
#include <map>

#define RED		"\033[1;31m"
#define	RESET	"\033[0m"

class BitcoinExchange {
public:
	static void	execute(std::ifstream& inputFile);

private:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& copy);
	BitcoinExchange& operator=(const BitcoinExchange& rhs);
	~BitcoinExchange();

	static std::map<std::string, float>		_dataMap;
	static std::pair<std::string, float>	_pair;
	static std::time_t						_inputDate;
	static std::time_t						_mapDate;

	static std::pair<std::string, float>	_validateLine(const std::string& line);
	static void			_saveCsvIntoMap();
	static std::string	_validateDate(const std::string& dateStr);
	static float		_validateValue(const std::string& valueStr);
	static void			_findDate();
	static void			_printOutput(std::map<std::string, float>::iterator it);
	static std::time_t	_getDateTime(const std::string& dateStr);
	static void			_errorMsg(std::string desc, std::string input);

	static void			_iterateMap(std::map<std::string, float>& map);

	class	FailedToOpenException: public std::exception {
		public: const char* what() const throw();
	};
};

#endif
