/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:40:34 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/03 17:12:17 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void) {
	{
		std::cout << GREEN
		<< "/*--- EX00 TESTS ------------------------------------------------*/"
		<< std::endl;

		std::cout << std:: endl << MAGENTA
		<< "/*--- CONSTRUCTORS --------------------------------*/" << std::endl;

		ClapTrap	clyde("Clyde");
		ClapTrap	copy(clyde);

		std::cout << std::endl << MAGENTA
		<< "/*--- MEMBER FUNCTIONS ----------------------------*/" << std::endl;

		clyde.attack("Shirley");
		clyde.takeDamage(9);
		clyde.beRepaired(1);

		std::cout << std::endl << MAGENTA
		<< "/*--- OUT OF ENERGY -------------------------------*/" << std::endl;

		clyde.setEnergyPoints(0);
		clyde.beRepaired(1);

		std::cout << std::endl << MAGENTA
		<< "/*--- OUT OF HITPOINTS ----------------------------*/" << std::endl;

		clyde.takeDamage(11);
		clyde.attack("Shirley");

		std::cout << std::endl << MAGENTA
		<< "/*--- DESTRUCTORS ---------------------------------*/" << std::endl;
	}

	{

		std::cout << std::endl << GREEN
		<< "/*--- EX01 TESTS ------------------------------------------------*/"
		<< std::endl;

		std::cout << std::endl <<  MAGENTA
		<< "/*--- CONSTRUCTORS --------------------------------*/" << std::endl;

		ClapTrap	clyde("Clyde");
		ScavTrap	shirley("Shirley");
		ScavTrap	copy(shirley);

		std::cout << std::endl << MAGENTA
		<< "/*--- MEMBER FUNCTIONS ----------------------------*/" << std::endl;

		shirley.attack("Clyde");
		shirley.beRepaired(1);
		shirley.guardGate();
		shirley.takeDamage(112);

		std::cout << std::endl << MAGENTA
		<< "/*--- DESTRUCTORS ---------------------------------*/" << std::endl;
	}
	return 0;
}
