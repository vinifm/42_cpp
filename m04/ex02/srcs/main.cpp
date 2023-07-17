/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:27:55 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/11 17:20:43 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongCat.hpp"
#include "../include/Brain.hpp"

void	title(std::string msg, std::string color);

/* Uncommenting Animal instances will display an error */
int	main(void)
{
	// Animal	animal;
	// const Animal*	meta = new Animal();
	const Animal*	dog = new Dog(); std::cout << std::endl;
	const Animal*	cat = new Cat(); std::cout << std::endl;

	dog->makeSound();
	cat->makeSound();

	std::cout << std::endl;
	delete dog;
	delete cat;
	return 0;
}

/* Print formatted title */
void	title(std::string msg, std::string color) {
	size_t	chars_left = 50 - msg.size();

	std::cout << std::endl << color << "/*--- " << msg << " ";
	for (size_t i = 0; i < chars_left; i++)
		std::cout << "-";
	std::cout << "*/" << RESET << std::endl;
}
