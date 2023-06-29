/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:40:34 by viferrei          #+#    #+#             */
/*   Updated: 2023/06/29 19:15:12 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap bob("Bob");

	bob.attack("Shirley");
	bob.takeDamage(9);
	bob.beRepaired(1);
	while (true) {
		if (bob.getEnergyPoints() == 0)
			break ;
		bob.beRepaired(1);
	}
	bob.beRepaired(1);
	bob.takeDamage(11);
	bob.attack("Shirley");
	return 0;
}
