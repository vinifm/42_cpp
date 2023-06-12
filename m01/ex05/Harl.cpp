/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:54:29 by viferrei          #+#    #+#             */
/*   Updated: 2023/06/12 20:14:28 by viferrei         ###   ########.fr       */
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
void Harl::complain(std::string level) {
	std::map<std::string, void (Harl::*)(void)> func_map;
	func_map["debug"] = &Harl::debug;
	func_map["info"] = &Harl::info;
	func_map["warning"] = &Harl::warning;
	func_map["error"] = &Harl::error;
	if (func_map.find(level) != func_map.end())
		(this->*(func_map[level]))();
}

Harl::Harl() {}
// Harl::Harl(const Harl& copy) {}
// Harl& Harl::operator=(const Harl& assign) {
// 	return *this;
// }
Harl::~Harl() {
	std::cout << "Harl was destroyed" << std::endl;
}
