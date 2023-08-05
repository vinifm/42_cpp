/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:56:21 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/05 16:53:58 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

int main(int argc, char** argv)
{
	if (argc == 1)
		std::cerr << "Missing argument" << std::endl;
	else if (argc > 2)
		std::cerr << "Too many arguments" << std::endl;
	else
		RPN::execute(argv[1]);
	return 0;
}
