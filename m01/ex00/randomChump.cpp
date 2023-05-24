/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:10:50 by viferrei          #+#    #+#             */
/*   Updated: 2023/05/24 16:55:20 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* It creates a zombie, name it, and the zombie announces itself */
void	randomChump(std::string name) {
	Zombie random(name);
	random.announce();
}
