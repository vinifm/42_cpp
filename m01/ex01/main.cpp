/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:36:13 by viferrei          #+#    #+#             */
/*   Updated: 2023/05/26 17:37:49 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	int	size;
	Zombie* horde;

	size = 5;
	horde = zombieHorde(size, "Johnny");
	for (int i = 0; i < size; i++) {
		std::cout << "Zombie number " << i << ": ";
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}
