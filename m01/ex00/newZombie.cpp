/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:10:46 by viferrei          #+#    #+#             */
/*   Updated: 2023/05/24 16:46:09 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*	Create a zombie, name it, and return it so you can use it outside of the
	function scope */
Zombie*	newZombie(std::string name) {
	return (new Zombie(name));
}
