/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:10:46 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/03 19:05:08 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>	// ifstream
#include <sstream>	// istringstream
#include <time.h>	// strptime
#include <map>

class BitcoinExchange {
public:
	static void	execute(std::ifstream& inputFile);

private:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& copy);
	BitcoinExchange& operator=(const BitcoinExchange& rhs);
	~BitcoinExchange();

	static std::map<std::string, float>	_dataMap;

	static void	_saveCsvIntoMap();

	class	FailedToOpenException: public std::exception {
		public: const char* what() const throw();
	};
};

#endif
