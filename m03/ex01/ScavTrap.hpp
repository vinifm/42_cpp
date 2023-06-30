/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:23:09 by viferrei          #+#    #+#             */
/*   Updated: 2023/06/30 17:59:28 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
public:
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& copy);
	ScavTrap& operator=(const ScavTrap& rhs);
	~ScavTrap();

	void	attack(const std::string& target);
	void	guardGate();

private:
	std::string	display_name();

};

#endif
