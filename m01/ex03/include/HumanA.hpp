/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:49:40 by viferrei          #+#    #+#             */
/*   Updated: 2023/05/30 18:08:29 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

/* Human A takes the weapon in its constructor and will always be armed */
class HumanA {
public:
	HumanA(std::string name = "Unknown", Weapon weapon);
	HumanA(const HumanA& copy);
	HumanA& operator=(const HumanA& assign);
	~HumanA();

	void attack();

private:
	std::string	_name;
	Weapon		_weapon;
};

#endif
