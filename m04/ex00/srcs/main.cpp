/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:27:55 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/03 20:42:44 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

void	title(std::string msg, std::string color);

int	main(void)
{
	title("CONSTRUCTORS", MAGENTA);
	const Animal*	meta = new Animal();

	meta->makeSound();

	delete meta;
	return 0;
}

// Print formatted title
void	title(std::string msg, std::string color) {
	size_t	chars_left = 50 - msg.size();

	std::cout << color << "/*--- " << msg << " ";
	for (size_t i = 0; i < chars_left; i++)
		std::cout << "-";
	std::cout << "*/" << std::endl;
}
