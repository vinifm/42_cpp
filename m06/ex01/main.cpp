/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:26:31 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/27 14:48:09 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	struct Data*	data1 = new Data;
	struct Data*	data2;
	uintptr_t		store_data;

	data1->num = 42;
	store_data = Serializer::serialize(data1);
	data2 = Serializer::deserialize(store_data);

	std::cout << data2->num << std::endl;

	delete data1;
}
