/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:05:46 by viferrei          #+#    #+#             */
/*   Updated: 2023/05/24 18:04:13 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*	Allocate N Zombie objects in a single allocation. Then initialize them with
	the name passed as parameter. Return a pointer to the first zombie */
Zombie*	zombieHorde(int N, std::string name) {
	Zombie* horde = new Zombie[N];
	// for (int i = 0; i < sizeof(*horde)/sizeof(horde[0]); i++)
	// 	horde[i].setName(name);
}
