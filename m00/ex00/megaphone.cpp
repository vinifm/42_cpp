/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:17:56 by viferrei          #+#    #+#             */
/*   Updated: 2023/03/28 19:42:33 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Returns the input in uppercase and no spaces between them */

#include <iostream>	// cout
#include <cctype>	// toupper

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++) {
		std::string	str = argv[i];
		for (std::string::iterator it = str.begin(); it != str.end(); it++)
			std::cout << (char) std::toupper(*it);
	}
	std::cout << std::endl;
}
