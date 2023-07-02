/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:40:34 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/02 20:04:15 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	std::cout << GREEN
	<< "/*--- EX00 TESTS ----------------------------------------------------*/"
	<< std::endl;

	std::cout << std:: endl << MAGENTA
	<< "/*--- CONSTRUCTORS ------------------------------------*/" << std::endl;

	ClapTrap	clyde("Clyde");
	ClapTrap	copy(clyde);

	std::cout << std::endl << MAGENTA
	<< "/*--- MEMBER FUNCTIONS --------------------------------*/" << std::endl;

	clyde.attack("Shirley");
	clyde.takeDamage(9);
	clyde.beRepaired(1);

	std::cout << std::endl << MAGENTA
	<< "/*--- OUT OF ENERGY -----------------------------------*/" << std::endl;

	clyde.setEnergyPoints(0);
	clyde.beRepaired(1);

	std::cout << std::endl << MAGENTA
	<< "/*--- OUT OF HITPOINTS --------------------------------*/" << std::endl;

	clyde.takeDamage(11);
	clyde.attack("Shirley");

	std::cout << std::endl << MAGENTA
	<< "/*--- DESTRUCTORS -------------------------------------*/" << std::endl;

	return 0;
}
