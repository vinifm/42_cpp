/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:56:36 by viferrei          #+#    #+#             */
/*   Updated: 2023/06/09 17:25:58 by viferrei         ###   ########.fr       */
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

void	iterate_line(std::string line_str, char **argv) {
	std::string			outfile_name = std::string(argv[1]) + ".replace";
	std::ofstream		outfile(outfile_name.c_str());
	std::stringstream	line(line_str);
	std::string			word, s1, s2;

	s1 = argv[2];
	s2 = argv[3];
	while (line >> word) {
		if (!word.compare(s1))
			std::cout << s2;
		else
			std::cout << word;
		if (line.eof())
			std::cout << "\n";
		else
			std::cout << " ";
	}
	outfile.close();
}

int	main(int argc, char **argv) {
	std::ifstream	infile(argv[1]);
	std::string		line_str;

	if (error_management(argc, argv))
		return (1);
	if (infile.is_open()) {
		while (getline(infile, line_str)) {
			iterate_line(line_str, argv);
		}
	}
	infile.close();
	return (0);
}
