/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:13:31 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/27 14:25:57 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*--- CONSTRUCTORS AND DESTRUCTOR --------------------------------------------*/

Serializer::Serializer() {}
Serializer::Serializer(const Serializer& copy) { (void) copy; }
Serializer& Serializer::operator=(const Serializer& rhs)
{
	(void) rhs;
	return *this;
}
Serializer::~Serializer() {}

/*--- MEMBER FUNCTIONS -------------------------------------------------------*/

uintptr_t	Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
