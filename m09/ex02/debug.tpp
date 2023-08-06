/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:08:44 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/06 19:15:29 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template < typename Container >
void	PmergeMe::_displayPairArr(const std::string& desc, const Container& cont)
{
	if (_DEBUG) {
		std::cout << desc << ": ";
		for (typename Container::const_iterator it = cont.begin();
			it != cont.end();
			++it)
			std::cout << "["  << it->first << ", " << it->second << "] ";
		std::cout << std::endl;
	}
}

template < typename Container >
void	PmergeMe::_displayArr(const std::string& desc, const Container& cont)
{
	if (_DEBUG) {
		std::cout << desc << ": ";
		for (typename Container::const_iterator it = cont.begin();
			it != cont.end();
			++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
}
