/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:45:20 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/05 16:52:28 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include "Animal.hpp"

class WrongAnimal {
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& copy);
	WrongAnimal& operator=(const WrongAnimal& rhs);
	virtual ~WrongAnimal();

	void makeSound() const;

	std::string getType() const;
	void		setType(std::string new_type);

protected:
	std::string	type;
};

#endif

