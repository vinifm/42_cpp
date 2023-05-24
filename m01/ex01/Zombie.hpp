/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:10:56 by viferrei          #+#    #+#             */
/*   Updated: 2023/05/24 17:27:22 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
public:
	Zombie(std::string name = "Unknown");
	Zombie(const Zombie& copy);
	Zombie& operator=(const Zombie& assign);
	~Zombie();

	void	setName(std::string name);
	void	announce();

private:
	std::string	name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif
