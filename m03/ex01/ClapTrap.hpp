/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:48:27 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/02 18:35:31 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

#define	YELLOW		"\033[1;33m"
#define	MAGENTA		"\033[1;35m"
#define	RESET		"\033[0m"

class ClapTrap {
public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& copy);
	ClapTrap& operator=(const ClapTrap& rhs);
	~ClapTrap();

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	bool		is_dead();
	bool		is_tired();
	std::string	display_name();

	// GETTERS
	std::string		getName() const;
	unsigned int	getHitPoints() const;
	unsigned int	getEnergyPoints() const;
	unsigned int	getAttackDamage() const;
	std::string		getClassName() const;

	// SETTERS
	void	setName(std::string);
	void	setHitPoints(unsigned int);
	void	setEnergyPoints(unsigned int);
	void	setAttackDamage(unsigned int);
	void	setClassName(std::string);

private:
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

	std::string		_className;
};

#endif
