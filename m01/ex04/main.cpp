/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:56:36 by viferrei          #+#    #+#             */
/*   Updated: 2023/06/09 18:50:14 by viferrei         ###   ########.fr       */
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

/*
	Find each occurence of s1 in line, erase it, replace it with s2 and write it
	in outfile
*/
void	search_line(std::ofstream& outfile, std::string line, char **argv) {
	std::string		s1, s2;
	size_t			found = 0;

	s1 = argv[2];
	s2 = argv[3];

	while (true) {
		found = line.find(s1, found);
		if (found != std::string::npos) {
			line.erase(found, s1.length());
			line.insert(found, s2);
			found += 1;
		}
		else {
			outfile << line << std::endl;
			break;
		}
	}
}

/* Open infile and pass each line to search_line */
int	main(int argc, char **argv) {
	if (error_management(argc, argv))
		return (1);

	std::ifstream	infile(argv[1]);
	std::string		line;
	std::string		outfile_name = std::string(argv[1]) + ".replace";
	std::ofstream	outfile(outfile_name.c_str());

	if (infile.is_open()) {
		while (getline(infile, line)) {
			search_line(outfile, line, argv);
		}
	}
	infile.close();
	outfile.close();
	return (0);
}
