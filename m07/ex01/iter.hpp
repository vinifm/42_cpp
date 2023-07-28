/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:24:46 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/28 11:57:33 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void	iter(const T* array, size_t len, void (*func)(const T& arrElement))
{
	if (!array || len <= 0)
		return ;
	for (size_t i = 0; i < len; i++)
		func(array[i]);
}

template <typename T>
void	iter(T* array, size_t len, void (*func)(T& arrElement))
{
	if (!array || len <= 0)
		return ;
	for (size_t i = 0; i < len; i++)
		func(array[i]);
}

template <typename T>
size_t	getSize(const T& array)
{
	return sizeof(array) / sizeof(array[0]);
}

template <typename T>
void	print(const T& arrElem)
{
	std::cout << arrElem << std::endl;
}

template <typename T>
void	addOne(T& arrElem)
{
	arrElem++;
}

#endif
