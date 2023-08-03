/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:16:15 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/31 16:35:26 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int	main(void)
{
	int	arr[] = {1, 4, 5, 42, 35, 42};
	std::vector<int>	vec(arr, arr + sizeof(arr) / sizeof(arr[0]));

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 42);
		std::cout << "Value " << *it << " at index "
			<< std::distance(vec.begin(), it) << std::endl;
		it = easyfind(vec, 21);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
