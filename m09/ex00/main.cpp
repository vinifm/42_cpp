/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:11:25 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/02 19:14:47 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char** argv)
{
	if (argc == 1) {
		std::cerr << "Error: could not open file" << std::endl;
		return 1;
	}
	else if (argc > 2) {
		std::cerr << "Error: Too many arguments" << std::endl;
		return 1;
	}

}
