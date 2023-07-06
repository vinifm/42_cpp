/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:27:55 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/06 19:21:01 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongCat.hpp"
#include "../include/Brain.hpp"

void	title(std::string msg, std::string color);
void	test_brain();

void	animal_array() {
	int	array_size = 4;
	if (array_size % 2)
		array_size++;

	title("ANIMAL ARRAY", MAGENTA);
	Animal*	animals[array_size];
	for (int i = 0; i < array_size; i++) {
		std::cout << WHITE "ANIMAL NUMBER " << i << RESET << std::endl;
		if (i % 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << std::endl;
	}

	title("DESTRUCTORS", MAGENTA);
	for (int i = 0; i < array_size; i++) {
		delete animals[i];
		std::cout << std::endl;
	}
}

void	test_copy() {
	title("ANIMAL COPIES", MAGENTA);
	Dog*	dog = new Dog();
	Cat		cat; std::cout << std::endl;

	Dog		copyDog(*dog); std::cout << std::endl;
	Cat		copyCat(cat); std::cout << std::endl;

	std::cout << "Address of dog: " << dog << std::endl;
	std::cout << "Address of copyDog: " << &copyDog << std::endl;
	std::cout << "Address of dog's brain: " << dog->_brain << std::endl;
	std::cout << "Address of copyDog: " << &copyDog << std::endl;

	title("DESTRUCTORS", MAGENTA);
	delete dog;
}

int	main(void)
{
	animal_array();
	test_copy();
	return 0;
}

void	iterate_ideas(const Brain& brain){
	for (int i = 0;
		i < (int)(sizeof(brain.ideas) / sizeof(brain.ideas[0]));
		i++) {
		std::cout << "idea no. " << i + 1 << ": " << brain.ideas[i] << std::endl;
	}
}

int	compare_ideas(const Brain& brain, const Brain& copy) {
	int	error = 0;
	for (int i = 0;
		i < (int)(sizeof(brain.ideas) / sizeof(brain.ideas[0]));
		i++) {
		if (brain.ideas[i] != copy.ideas[i])
			error = -1;
	}
	if (error)
		std::cout << RED "Brains are not the same." RESET << std::endl;
	else
		std::cout << GREEN "Brains are the same." RESET << std::endl;
	return error;
}

void	test_brain() {
	Brain	brain;
	Brain	copy(brain);

	compare_ideas(brain, copy);
	// iterate_ideas(brain);
}

// Print formatted title
void	title(std::string msg, std::string color) {
	size_t	chars_left = 50 - msg.size();

	std::cout << std::endl << color << "/*--- " << msg << " ";
	for (size_t i = 0; i < chars_left; i++)
		std::cout << "-";
	std::cout << "*/" << RESET << std::endl;
}
