/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:27:55 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/05 16:48:16 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongCat.hpp"

void	title(std::string msg, std::string color);

int	main(void)
{
	{
		title("CONSTRUCTORS", MAGENTA);
		const Animal*	meta = new Animal();
		const Animal*	dog = new Dog();
		const Animal*	cat = new Cat();

		title("TYPES", MAGENTA);
		std::cout << meta->getType() << std::endl;
		std::cout << dog->getType() << std::endl;
		std::cout << cat->getType() << std::endl;

		title("MAKESOUND", MAGENTA);
		meta->makeSound();
		dog->makeSound();
		cat->makeSound();

		title("WRONG ANIMAL AND WRONG CAT", MAGENTA);
		const WrongAnimal*	wrongMeta = new WrongAnimal();
		const WrongAnimal*	wrongCat = new WrongCat();

		wrongMeta->makeSound();
		wrongCat->makeSound();

		title("DESTRUCTORS", MAGENTA);
		delete meta;
		delete dog;
		delete cat;
		delete wrongMeta;
		delete wrongCat;
	}
	{
		title("TESTING COPIES", BLUE);
		Animal*	meta = new Animal();
		Dog		doggy;
		Cat		kitty;

		title("COPY CONSTRUCTORS", BLUE);
		Animal	metaCopy(*meta);
		Dog		doggyCopy(doggy);
		Cat		kittyCopy(kitty);

		title("COPY TYPES", BLUE);
		std::cout << metaCopy.getType() << std::endl;
		std::cout << doggyCopy.getType() << std::endl;
		std::cout << kittyCopy.getType() << std::endl;

		title("COPY SOUNDS", BLUE);
		metaCopy.makeSound();
		doggyCopy.makeSound();
		kittyCopy.makeSound();

		title("DESTRUCTORS", BLUE);
		delete meta;
	}
	return 0;
}

// Print formatted title
void	title(std::string msg, std::string color) {
	size_t	chars_left = 50 - msg.size();

	std::cout << std::endl << color << "/*--- " << msg << " ";
	for (size_t i = 0; i < chars_left; i++)
		std::cout << "-";
	std::cout << "*/" << RESET << std::endl;
}
