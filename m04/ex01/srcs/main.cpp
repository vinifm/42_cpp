/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:27:55 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/07 17:14:09 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongCat.hpp"
#include "../include/Brain.hpp"

void	title(std::string msg, std::string color);
int		compare_ideas(const Brain& brain, const Brain& copy);
void	iterate_ideas(const Brain& brain);

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
	title("ANIMAL COPIES", BLUE);
	Dog*	dog = new Dog(); std::cout << std::endl;
	Cat		cat; std::cout << std::endl;
	Dog		puppy(*dog); std::cout << std::endl;
	Cat		kitty(cat); std::cout << std::endl;

	std::cout << WHITE "Deep copies:" RESET << std::endl;
	if (dog->getBrain() != puppy.getBrain())
		std::cout << "These dogs do not share the same brain!" << std::endl;
	if (cat.getBrain() != kitty.getBrain())
		std::cout << "Neither do these cats!" << std::endl;

	title("BRAINSTORMING", BLUE);
	std::cout << "The animals come closer and share these "
		<< "precious pieces of wisdom: " << std::endl
		<< dog->getBrain()->ideas[0] << std::endl
		<< puppy.getBrain()->ideas[1] << std::endl
		<< cat.getBrain()->ideas[0] << std::endl
		<< kitty.getBrain()->ideas[1] << std::endl;

	title("COPIES DESTRUCTORS", BLUE);
	delete dog;
}

/* srand() ensures brains' ideas are randomized */
int	main(void)
{
	std::srand((unsigned int) time(NULL));
	animal_array();
	test_copy();

	return 0;
}


/* Print all ideas in a brain */
void	iterate_ideas(const Brain& brain) {
	for (int i = 0;
		i < (int)(sizeof(brain.ideas) / sizeof(brain.ideas[0]));
		i++) {
		std::cout << "idea n. " << i + 1 << ": " << brain.ideas[i] << std::endl;
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
		std::cout << RED "Ideas are not the same." RESET << std::endl;
	else
		std::cout << GREEN "Ideas are the same." RESET << std::endl;
	return error;
}

/* Print formatted title */
void	title(std::string msg, std::string color) {
	size_t	chars_left = 50 - msg.size();

	std::cout << std::endl << color << "/*--- " << msg << " ";
	for (size_t i = 0; i < chars_left; i++)
		std::cout << "-";
	std::cout << "*/" << RESET << std::endl;
}
