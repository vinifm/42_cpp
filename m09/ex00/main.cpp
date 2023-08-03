/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:11:25 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/03 18:14:42 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char** argv)
{
	std::ifstream	input_file;
	if (argc == 1) {
		std::cerr << "Error: Missing argument" << std::endl;
		return 1;
	}
	else if (argc > 2) {
		std::cerr << "Error: Too many arguments" << std::endl;
		return 1;
	}
	input_file.open(argv[1], std::ifstream::in);
	if (!input_file.is_open()) {
		std::cerr << "Error: Failed to open file" << std::endl;
		return 1;
	}
	BitcoinExchange::execute(input_file);
	input_file.close();
	return 0;
}
