/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:10:56 by viferrei          #+#    #+#             */
/*   Updated: 2023/05/17 18:59:07 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie {
public:
	Zombie(void);
	~Zombie(void);
	Zombie(const Zombie &copy);
	Zombie& operator=(const Zombie &copy);

	void	announce(void);
	Zombie*	newZombie(std::string name);
	void	randomChump(std::string name);

private:
	std::string	name;
}

#endif
