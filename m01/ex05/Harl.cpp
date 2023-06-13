/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:54:29 by viferrei          #+#    #+#             */
/*   Updated: 2023/06/13 17:13:11 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void) {
	std::cout << "I love extra hummus for my veggie-indie-alternative-disruptive-woke-falafel. I really do!" \
		<< std::endl;
}
void Harl::info(void) {
	std::cout << "I cannot believe adding extra hummus costs more money. You didn't put enough hummus in my falafel! If you did, I wouldn't be asking for more!" \
		<< std::endl;
}
void Harl::warning(void) {
	std::cout << "I think I deserve to have some extra hummus for free. I've been coming for years whereas you started working here since last month" \
		<< std::endl;
}
void Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now"	\
	<< std::endl;
}

/*
	Declare an array of function pointers and a string array with their
	respective levels. Iterate through the latter until level is found.
*/
void Harl::complain(std::string level) {
	int		i = -1;

	void	(Harl::*func_array[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string	levels[] = {"debug", "info", "warning", "error"};
	while (levels[++i] != level && i < 4)
		continue;
	if (i == 4)
		return ;
	(this->*func_array[i])();
}

Harl::Harl() {}
Harl::~Harl() {
	std::cout << "Harl was destroyed" << std::endl;
}
