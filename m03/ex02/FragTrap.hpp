/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 19:06:39 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/02 19:53:06 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#define	B_GREEN	"\033[1;92m" // Bright green

class FragTrap : public ClapTrap {
public:
	FragTrap(std::string name);
	FragTrap(const FragTrap& copy);
	FragTrap& operator=(const FragTrap& rhs);
	~FragTrap();

	void	highFiveGuys();
};

#endif
