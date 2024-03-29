/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:11:11 by viferrei          #+#    #+#             */
/*   Updated: 2023/06/06 15:47:05 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

/* HumanB has a setWeapon method and may not always be armed */
class HumanB {
public:
	HumanB(std::string name = "Unknown");
	HumanB(const HumanB& copy);
	HumanB& operator=(const HumanB& assign);
	~HumanB();

	void	attack();
	void	setWeapon(Weapon& weapon);

private:
	std::string	_name;
	Weapon*		_weapon;
};

#endif
