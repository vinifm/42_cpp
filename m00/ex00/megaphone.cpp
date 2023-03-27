/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:17:56 by viferrei          #+#    #+#             */
/*   Updated: 2023/03/27 18:53:44 by viferrei         ###   ########.fr       */
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
		for (size_t j = 0; argv[i][j] != '\0'; j++)
			std::cout << (char) std::toupper(argv[i][j]);
	}
	std::cout << std::endl;
}
