/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:56:36 by viferrei          #+#    #+#             */
/*   Updated: 2023/06/06 18:06:26 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	PARAMETERS: <filename>, <s1>, <s2>
	Replaces every occurrence of <s1> with <s2> in a new <filename>.replace file
*/

#include "main.hpp"

int	error_management(int argc, char **argv){
	std::ifstream	infile(argv[1]);

	if (argc != 4) {
		std::cout << "Invalid number of arguments" << std::endl;
		return (1);
	}
	if (!infile.is_open()) {
		std::cout << "Unable to open file" << std::endl;
		return (2);
	}
	infile.close();
	return (0);
}

int	main(int argc, char **argv) {
	error_management(argc, argv);
	(void) argc;
	(void) argv;
	return (0);
}
