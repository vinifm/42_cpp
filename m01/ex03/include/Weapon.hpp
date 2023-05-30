/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:44:09 by viferrei          #+#    #+#             */
/*   Updated: 2023/05/30 17:47:58 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon {
public:
	Weapon(std::string type = "bare hands");
	Weapon(const Weapon& copy);
	Weapon& operator=(const Weapon& assign);
	~Weapon();

	const std::string&	getType() const;
	void				setType(std::string type);

private:
	std::string	_type;
};

#endif
