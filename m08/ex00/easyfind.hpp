/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:02:32 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/31 16:28:01 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>		// exception;
#include <algorithm>	// find

class NumberNotFoundException: public std::exception
{
	public: virtual const char* what() const throw() {
		return "Element not found";
	};
};

/*
	Find the first occurrence of num in container, with T as a container of
	integers.
*/
template <typename T>
typename	T::iterator easyfind(T& container, int num)
{
	typename T::iterator it = std::find(container.begin(), container.end(), num);
	if (it == container.end())
		throw NumberNotFoundException();
	return it;
}

#endif
