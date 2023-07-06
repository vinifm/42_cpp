/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:44:47 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/06 18:47:42 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "../include/Animal.hpp"

class Cat : public Animal {
public:
	Cat();
	Cat(const Cat& copy);
	Cat& operator=(const Cat& rhs);
	~Cat();

	virtual void makeSound() const;

private:
	Brain*	_brain;
};

#endif
