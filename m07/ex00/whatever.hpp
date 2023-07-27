/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:06:04 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/27 20:27:49 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#define	MAGENTA		"\033[1;35m"
#define	RESET		"\033[0m"

template <typename T>
void	swap(T& a, T& b)
{
	T temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T>
const T&	min(const T& a, const T& b)
{
	return (a < b ? a : b);
}

template <typename T>
const T&	max(const T& a, const T& b)
{
	return (a > b ? a : b);
}

#endif
