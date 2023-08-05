/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:56:21 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/05 19:31:45 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

int main(int argc, char** argv)
{
	if (argc == 1)
		std::cerr << "Missing argument" << std::endl;
	else if (argc > 2)
		std::cerr << "Too many arguments" << std::endl;
	else {
		try { RPN::execute(argv[1]); }
		catch (std::exception& e) {std::cout << e.what() << std::endl; }
	}
	return 0;
}
