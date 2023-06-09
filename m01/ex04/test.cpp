/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:46:01 by viferrei          #+#    #+#             */
/*   Updated: 2023/06/09 18:52:35 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "main.hpp"

//	Print str in bold yellow
void	test_case(std::string str) {
	std::cout << YELLOW << "\n" << str << " " << RESET << std::flush;
}

//	Print command and execute it
void	exec(std::string args) {
	std::string	program = "./replacer ";
	std::string	cmd = program + args;
	std::cout << cmd << std::endl;
	std::cout << RED << "Output: " << RESET << std::flush;
	system(cmd.c_str());
}

int	main(void) {

	std::cout << YELLOW << "\n<test_case>: "<< RESET << "<command>" << std::endl;

	test_case("Invalid number of arguments:");
	exec("file1");

	test_case("Non-existent file:");
	exec("nofile s1 s2");

	test_case("Permission denied:");
	system("touch infile");
	system("chmod 000 infile");
	exec("infile s1 s2");
	system("rm -rf infile");

	test_case("Simple replacement:");
	std::ofstream	outfile("infile.txt");
	outfile << "My baby lives in shades of blue\n";
	outfile << "Blue eyes and jazz and attitude\n";
	outfile << "My baby lives in California too\n";
	outfile << "My baby drives a Chevy Malibu\n";
	outfile << "And when my baby calls, my baby calls for me and not for you\n";
	outfile << "my baby lives for love, my baby loves his drugs, my baby loves his baby too."\
	<< std::endl;
	outfile.close();
	exec("infile.txt baby daddy");
	system("cat infile.txt.replace");

	test_case("Compound string:");
	exec("infile.txt \"My baby\" \"My annoying mother-in-law\"");
	system("cat infile.txt.replace");

	test_case("Empty strings:");
	exec("infile.txt \" \" \"\"");
	system("cat infile.txt.replace");
}
