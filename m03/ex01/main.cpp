/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:40:34 by viferrei          #+#    #+#             */
/*   Updated: 2023/06/30 18:05:41 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void) {
	std::cout << MAGENTA
	<< "/*--- CONSTRUCTORS ------------------------------------*/" << std::endl;

	ClapTrap	clyde("Clyde");
	ScavTrap	shirley("Shirley");
	ScavTrap	copy(shirley);

	std::cout << std::endl << MAGENTA
	<< "/*--- MEMBER FUNCTIONS --------------------------------*/" << std::endl;

	shirley.attack("Clyde");
	shirley.beRepaired(1);
	shirley.takeDamage(10);

	std::cout << std::endl << MAGENTA
	<< "/*--- DESTRUCTORS -------------------------------------*/" << std::endl;

	return 0;
}
