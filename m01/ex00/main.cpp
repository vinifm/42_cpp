/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:36:13 by viferrei          #+#    #+#             */
/*   Updated: 2023/05/24 16:58:27 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie	who = Zombie();
	Zombie	john("John");
	Zombie*	pointy = newZombie("Pointy");

	who.announce();
	john.announce();
	pointy->announce();
	randomChump("Random");
	delete pointy;
	return (0);
}
