/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:40:34 by viferrei          #+#    #+#             */
/*   Updated: 2023/06/29 21:28:48 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void	out_of_energy_loop(ClapTrap& clap) {
	while (true) {
		if (clap.getEnergyPoints() == 0)
			break ;
		clap.beRepaired(1);
	}
}

int	main(void) {
	ClapTrap	clyde("Clyde");
	ClapTrap	copy(clyde);
	ScavTrap	shirley("Shirley");

	clyde.attack("Shirley");
	// out_of_energy_loop(clyde);
	clyde.attack("Shirley");
	return 0;
}
