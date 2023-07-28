/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:32:12 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/28 12:04:45 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	std::string	str_arr[] = {"hello", "big", "world"};
	iter(str_arr, getSize(str_arr), print);
	std::cout << std::endl;

	int	int_arr[3] = {1, 2, 3};
	iter(int_arr, getSize(int_arr), addOne);
	iter(int_arr, getSize(int_arr), print);
	std::cout << std::endl;

	char str[] = "abc";
	iter(str, getSize(int_arr), addOne);
	iter(str, getSize(int_arr), print);
}
