/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:17:56 by viferrei          #+#    #+#             */
/*   Updated: 2023/03/22 17:50:26 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Returns the input in uppercase */

#include <iostream>
#include <cctype>	// toupper()

int main(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		// turn into uppercase
		std::cout << argv[i];
	}
	std::cout << std::endl;
}
