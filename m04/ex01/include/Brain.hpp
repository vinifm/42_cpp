/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:40:01 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/07 17:13:22 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <cstdlib>
#include <unistd.h>

#define	RESET	"\033[0m"
#define	PURPLE	"\033[1;38;5;105m"

class Brain {
public:
	Brain();
	Brain(const Brain& copy);
	Brain& operator=(const Brain& rhs);
	~Brain();

	std::string	ideas[100];

private:
	static std::string _ideaPool[100];
};

#endif
