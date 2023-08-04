/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:10:46 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/04 15:10:45 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>	// ifstream
#include <sstream>	// istringstream
#include <time.h>	// strptime
#include <limits.h>
#include <map>

#define RED		"\033[1;31m"
#define	RESET	"\033[0m"

typedef struct	s_date {
	bool		valid;
	int			year;
	int			month;
	int			day;
}				t_date;

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

	static std::pair<std::string, float>	_validateLine(const std::string& line);
	static void			_saveCsvIntoMap();
	static std::string	_validateDate(const std::string& dateStr);
	static float		_validateValue(const std::string& valueStr);
	static void			_printOutput();
	static t_date		_getDateStruct(const std::string& dateStr);
	static void			_errorMsg(std::string desc, std::string input);

	static void			_iterateMap(std::map<std::string, float>& map);

	class	FailedToOpenException: public std::exception {
		public: const char* what() const throw();
	};
};

#endif
