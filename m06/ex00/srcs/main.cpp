/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:57:45 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/27 20:14:27 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

int	main(int argc, char** argv)
{
	if (argc == 1) {
		std::cout << "Missing argument" << std::endl;
		return -1;
	}
	else if (argc > 2) {
		std::cout << "Too many arguments" << std::endl;
		return -2;
	}
	try { ScalarConverter::convert(argv[1]); }
	catch (std::exception& e) { std::cout << e.what() << std::endl; }
	return 0;
}
